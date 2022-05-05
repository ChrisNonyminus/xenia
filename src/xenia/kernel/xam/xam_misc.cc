/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/emulator.h"
#include "xenia/kernel/kernel_flags.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xam/xam_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xam {

static uint32_t dash_context_ = 0; // don't know what this does right now

void XamSetDashContext_entry(dword_t context) {
  dash_context_ = context.value();
}
DECLARE_XAM_EXPORT1(XamSetDashContext, kNone, kStub);

dword_result_t XamGetDashContext_entry() {
  return dash_context_;
}
DECLARE_XAM_EXPORT1(XamGetDashContext, kNone, kStub);

}  // namespace xam
}  // namespace kernel
}  // namespace xe

DECLARE_XAM_EMPTY_REGISTER_EXPORTS(Misc);