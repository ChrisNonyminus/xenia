/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "opencv2/imgproc.hpp"

#include "xenia/base/logging.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xboxkrnl/xboxkrnl_private.h"
#include "xenia/kernel/xusbcam.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xboxkrnl {

dword_result_t XUsbcamCreate_entry(dword_t buffer,
                                   dword_t buffer_size,  // 0x4B000 640x480?
                                   lpdword_t handle_out) {
  // This function should return success.
  // It looks like it only allocates space for usbcam support.
  // returning error code might cause games to initialize incorrectly.
  // "Carcassonne" initalization function checks for result from this
  // function. If value is different than 0 instead of loading
  // rest of the game it returns from initalization function and tries
  // to run game normally which causes crash, due to uninitialized data.
  auto camera = object_ref<XUsbcam>(new XUsbcam(kernel_state()));
  if (camera->Initialize(buffer_size) != X_ERROR_SUCCESS) {
    return X_ERROR_DEVICE_NOT_CONNECTED;
  }
  *handle_out = camera->handle();
  //cv::Mat frame{};
  //camera->capture_device().read(frame);
  //
  //cv::Mat frame_rgb{};
  //cv::cvtColor(frame, frame_rgb, cv::COLOR_BGR2YUV);

  //memcpy(kernel_memory()->TranslateVirtual(buffer), frame_rgb.data,
  //       buffer_size);

  return X_STATUS_SUCCESS;
}
DECLARE_XBOXKRNL_EXPORT1(XUsbcamCreate, kNone, kStub);

dword_result_t XUsbcamGetState_entry() {
  auto cams = kernel_state()->object_table()->GetObjectsByType<XUsbcam>(
      XObject::Type::Usbcam);

  if (cams.begin() == cams.end()) {
    return 0;
  }

  // 0 = not connected.
  // 1 = initialized
  // 2 = connected
  return 2;
}
DECLARE_XBOXKRNL_EXPORT1(XUsbcamGetState, kNone, kStub);

dword_result_t XUsbcamReadFrame_entry(dword_t handle, dword_t buffer,
                                dword_t buffer_size, dword_t r6,
                                      dword_t overlapped_ptr) {
  auto cams = kernel_state()->object_table()->GetObjectsByType<XUsbcam>(
      XObject::Type::Usbcam);

  if (cams.begin() == cams.end()) {
    return 0;
  }

  auto& cap = cams.begin()->get()->capture_device();
  if (!cap.isOpened())
      cap.open(0);
  if (cap.isOpened()) {
    auto width = cams.begin()->get()->frame_width();   // 640 pixels wide
    auto height = cams.begin()->get()->frame_height(); // 480 pixels tall
    cv::Mat frame(height, width, CV_8UC4);
    cap.read(frame);

    cv::cvtColor(frame, frame, cv::COLOR_BGR2BGRA);
    frame.resize(480);


    memcpy(kernel_memory()->TranslateVirtual(buffer), frame.data,
           width * height * 4);
    /*FILE* test = fopen("webcam_test.bin", "wb");
    fwrite(frame.data, 1, 640 * 480 * 4, test);*/
    return X_STATUS_SUCCESS;
  }
  XELOGE("cv::VideoCapture device failed to open!");
  return 0;
}
DECLARE_XBOXKRNL_EXPORT1(XUsbcamReadFrame, kNone, kStub);

dword_result_t XUsbcamSetConfig_entry(dword_t r3, dword_t r4, dword_t r5,
                                      dword_t r6,
                                dword_t r7, dword_t r8, dword_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XBOXKRNL_EXPORT1(XUsbcamSetConfig, kNone, kStub);

dword_result_t XUsbcamSetCaptureMode_entry(dword_t r3, dword_t r4, dword_t r5,
                                           dword_t r6, dword_t r7, dword_t r8,
                                           dword_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XBOXKRNL_EXPORT1(XUsbcamSetCaptureMode, kNone, kStub);

}  // namespace xboxkrnl
}  // namespace kernel
}  // namespace xe

DECLARE_XBOXKRNL_EMPTY_REGISTER_EXPORTS(Usbcam);
