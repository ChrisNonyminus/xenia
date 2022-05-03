/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2021 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XUSBCAM_H_
#define XENIA_KERNEL_XUSBCAM_H_

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "xenia/kernel/xobject.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {

class XUsbcam : public XObject {
 public:
  static const XObject::Type kObjectType = XObject::Type::Usbcam;

  XUsbcam(KernelState* kernel_state);
  virtual ~XUsbcam();

  X_STATUS Initialize(uint32_t buffer_size);
  cv::VideoCapture& capture_device() { return capture_device_; }
  uint32_t frame_width() { return frame_width_; }
  uint32_t frame_height() { return frame_height_; }

 private:
  cv::VideoCapture capture_device_;
  uint32_t frame_width_;
  uint32_t frame_height_;
};

}  // namespace kernel
}  // namespace xe

#endif