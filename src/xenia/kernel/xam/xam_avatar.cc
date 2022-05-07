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
#include "xenia/kernel/xam/xam_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xam {

dword_result_t XamAvatarInitialize_entry(
    dword_t unk1,              // 1, 4, etc
    dword_t unk2,              // 0 or 1
    dword_t processor_number,  // for thread creation?
    lpdword_t function_ptrs,   // 20b, 5 pointers
    lpunknown_t unk5,          // ptr in data segment
    dword_t unk6               // flags - 0x00300000, 0x30, etc
) {
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarInitialize, kAvatars, kStub);

dword_result_t XamAvatarLoadAnimation_entry(lpunknown_t r3, unknown_t r4,
                                            unknown_t r5, unknown_t r6,
                                            unknown_t r7, unknown_t r8,
                                            unknown_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarLoadAnimation, kAvatars, kStub);

dword_result_t XamAvatarGetManifestLocalUser_entry(lpunknown_t r3, unknown_t r4,
                                                   unknown_t r5, unknown_t r6,
                                                   unknown_t r7, unknown_t r8,
                                                   unknown_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetManifestLocalUser, kAvatars, kStub);

dword_result_t XamAvatarSetManifest_entry(lpunknown_t r3, unknown_t r4,
                                                   unknown_t r5, unknown_t r6,
                                                   unknown_t r7, unknown_t r8,
                                                   unknown_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarSetManifest, kAvatars, kStub);

void XamAvatarShutdown_entry() {
  // No-op.
}
DECLARE_XAM_EXPORT1(XamAvatarShutdown, kAvatars, kStub);

}  // namespace xam
}  // namespace kernel
}  // namespace xe

DECLARE_XAM_EMPTY_REGISTER_EXPORTS(Avatar);
