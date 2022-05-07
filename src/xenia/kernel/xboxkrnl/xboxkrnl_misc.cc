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
#include "xenia/kernel/xthread.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xboxkrnl {

void KeEnableFpuExceptions_entry(dword_t enabled) {
  // TODO(benvanik): can we do anything about exceptions?
}
DECLARE_XBOXKRNL_EXPORT1(KeEnableFpuExceptions, kNone, kStub);

dword_result_t EtxProducerRegister_entry(unknown_t r3, unknown_t r4, unknown_t r5, unknown_t r6,
                      unknown_t r7, unknown_t r8, unknown_t r9) {
  return X_STATUS_SUCCESS;
}
DECLARE_XBOXKRNL_EXPORT1(EtxProducerRegister, kNone, kStub);

}  // namespace xboxkrnl
}  // namespace kernel
}  // namespace xe

DECLARE_XBOXKRNL_EMPTY_REGISTER_EXPORTS(Misc);
