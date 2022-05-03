/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2021 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/kernel/xusbcam.h"

namespace xe {
namespace kernel {

XUsbcam::XUsbcam(KernelState* kernel_state)
    : XObject(kernel_state, kObjectType) {
  frame_width_ = 0;
  frame_height_ = 0;
}

XUsbcam::~XUsbcam() = default;

X_STATUS XUsbcam::Initialize(uint32_t buffer_size) {

  if (buffer_size == 0x4B000) { // 0x4B000 is the product of 640 and 480
    frame_width_ = 640;
    frame_height_ = 480;
  }

  capture_device_ = cv::VideoCapture(0, cv::VideoCaptureAPIs::CAP_V4L2);
  capture_device_.set(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH,
                      frame_width_);
  capture_device_.set(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT,
                      frame_height_);
  capture_device_.set(cv::VideoCaptureProperties::CAP_PROP_FPS, 30);
  capture_device_.set(cv::VideoCaptureProperties::CAP_PROP_CONVERT_RGB, true);
  capture_device_.set(cv::VideoCaptureProperties::CAP_PROP_FOURCC,
                      cv::VideoWriter::fourcc('B', 'G', 'R', 'A'));

  return X_ERROR_SUCCESS;
}

}  // namespace kernel
}  // namespace xe
