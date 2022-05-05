/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xboxkrnl/xboxkrnl_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xboxkrnl {

void HalReturnToFirmware_entry(dword_t routine) {
  // void
  // IN FIRMWARE_REENTRY  Routine

  // Routine must be 1 'HalRebootRoutine'
  assert_true(routine == 1);

  // TODO(benvank): diediedie much more gracefully
  // Not sure how to blast back up the stack in LLVM without exceptions, though.
  XELOGE("Game requested shutdown via HalReturnToFirmware");
  exit(0);
}
DECLARE_XBOXKRNL_EXPORT2(HalReturnToFirmware, kNone, kStub, kImportant);

void HalGetCurrentAVPack_entry(pointer_t<X_VIDEO_MODE> video_mode, dword_t r4,
                               dword_t r5, dword_t buffer_ptr, dword_t buffer_size,
                               dword_t width, dword_t height) {
  // parameters assumed from nearby implemented function calls that had the same values in the registers as this function.
  // dunno what r4 and r5 are
  // ???
}
DECLARE_XBOXKRNL_EXPORT1(HalGetCurrentAVPack, kNone, kStub);

}  // namespace xboxkrnl
}  // namespace kernel
}  // namespace xe

DECLARE_XBOXKRNL_EMPTY_REGISTER_EXPORTS(Hal);
