// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2c_master.h for the primary calling header

#include "Vi2c_master.h"
#include "Vi2c_master__Syms.h"

//==========

Vi2c_master::Vi2c_master(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vi2c_master__Syms* __restrict vlSymsp = __VlSymsp = new Vi2c_master__Syms(_vcontextp__, this, name());
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vi2c_master::__Vconfigure(Vi2c_master__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vi2c_master::~Vi2c_master() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vi2c_master::_settle__TOP__2(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_settle__TOP__2\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_intr = vlTOPp->i2c_master__DOT__intr_done;
    vlTOPp->io_i2c_scl = (1U & ((~ (IData)(vlTOPp->i2c_master__DOT__i2c_scl_enable)) 
                                | (~ (IData)(vlTOPp->clock))));
    vlTOPp->i2c_master__DOT___GEN_5 = (0x7fffU & ((0U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__count))
                                                   ? (IData)(vlTOPp->i2c_master__DOT__count)
                                                   : 
                                                  ((IData)(vlTOPp->i2c_master__DOT__count) 
                                                   - (IData)(1U))));
    vlTOPp->i2c_master__DOT___GEN_44 = ((2U == (IData)(vlTOPp->i2c_master__DOT__state))
                                         ? (IData)(vlTOPp->i2c_master__DOT__intr_done)
                                         : ((3U == (IData)(vlTOPp->i2c_master__DOT__state))
                                             ? (IData)(vlTOPp->i2c_master__DOT__intr_done)
                                             : ((4U 
                                                 == (IData)(vlTOPp->i2c_master__DOT__state))
                                                 ? (IData)(vlTOPp->i2c_master__DOT__intr_done)
                                                 : 
                                                ((5U 
                                                  == (IData)(vlTOPp->i2c_master__DOT__state))
                                                  ? (IData)(vlTOPp->i2c_master__DOT__intr_done)
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__state))
                                                   ? (IData)(vlTOPp->i2c_master__DOT__intr_done)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                   | (IData)(vlTOPp->i2c_master__DOT__intr_done)))))));
    vlTOPp->io_ready = ((~ (IData)(vlTOPp->reset)) 
                        & ((0U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                           & (1U == (IData)(vlTOPp->i2c_master__DOT__state))));
    vlTOPp->io_stop = ((~ (IData)(vlTOPp->reset)) & 
                       ((0U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                        & ((1U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                           & ((2U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                              & ((3U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                 & ((4U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                    & ((5U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                       & ((6U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                          & (7U == (IData)(vlTOPp->i2c_master__DOT__state))))))))));
    vlTOPp->i2c_master__DOT___GEN_61 = ((IData)(vlTOPp->reset)
                                         ? 0U : ((0U 
                                                  == (IData)(vlTOPp->i2c_master__DOT__state))
                                                  ? 
                                                 ((IData)(vlTOPp->io_start)
                                                   ? 1U
                                                   : 0U)
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__state))
                                                   ? 2U
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->i2c_master__DOT__state))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->i2c_master__DOT__count))
                                                     ? 3U
                                                     : 2U)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->i2c_master__DOT__state))
                                                     ? 4U
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->i2c_master__DOT__state))
                                                      ? 
                                                     ((IData)(vlTOPp->io_i2c_sda_in)
                                                       ? 7U
                                                       : 5U)
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__state))
                                                       ? 
                                                      ((0U 
                                                        == (IData)(vlTOPp->i2c_master__DOT__count))
                                                        ? 6U
                                                        : 5U)
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlTOPp->i2c_master__DOT__state))
                                                        ? 7U
                                                        : 0U))))))));
    vlTOPp->io_i2c_sda = ((IData)(vlTOPp->reset) | 
                          ((0U == (IData)(vlTOPp->i2c_master__DOT__state)) 
                           | ((1U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                              & ((2U == (IData)(vlTOPp->i2c_master__DOT__state))
                                  ? ((6U >= (IData)(vlTOPp->i2c_master__DOT__count))
                                      ? (0x7fU & ((IData)(vlTOPp->i2c_master__DOT__saved_addr) 
                                                  >> (IData)(vlTOPp->i2c_master__DOT__count)))
                                      : 0U) : ((3U 
                                                == (IData)(vlTOPp->i2c_master__DOT__state))
                                                ? (IData)(vlTOPp->io_read_write)
                                                : (
                                                   (4U 
                                                    == (IData)(vlTOPp->i2c_master__DOT__state))
                                                    ? (IData)(vlTOPp->io_i2c_sda_in)
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlTOPp->i2c_master__DOT__state))
                                                     ? 
                                                    ((7U 
                                                      >= (IData)(vlTOPp->i2c_master__DOT__count))
                                                      ? 
                                                     (0xffU 
                                                      & ((IData)(vlTOPp->io_data) 
                                                         >> (IData)(vlTOPp->i2c_master__DOT__count)))
                                                      : 0U)
                                                     : 
                                                    ((6U 
                                                      != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                     | (IData)(vlTOPp->io_i2c_sda_in)))))))));
    vlTOPp->i2c_master__DOT___GEN_43 = ((2U == (IData)(vlTOPp->i2c_master__DOT__state))
                                         ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                         : ((3U == (IData)(vlTOPp->i2c_master__DOT__state))
                                             ? (IData)(vlTOPp->i2c_master__DOT__count)
                                             : ((4U 
                                                 == (IData)(vlTOPp->i2c_master__DOT__state))
                                                 ? 
                                                ((IData)(vlTOPp->io_i2c_sda_in)
                                                  ? (IData)(vlTOPp->i2c_master__DOT__count)
                                                  : 7U)
                                                 : 
                                                ((5U 
                                                  == (IData)(vlTOPp->i2c_master__DOT__state))
                                                  ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                                  : (IData)(vlTOPp->i2c_master__DOT__count)))));
}

void Vi2c_master::_eval_initial(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval_initial\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vi2c_master::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::final\n"); );
    // Variables
    Vi2c_master__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vi2c_master::_eval_settle(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval_settle\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vi2c_master::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_start = VL_RAND_RESET_I(1);
    io_addr = VL_RAND_RESET_I(7);
    io_data = VL_RAND_RESET_I(8);
    io_read_write = VL_RAND_RESET_I(1);
    io_i2c_sda_in = VL_RAND_RESET_I(1);
    io_i2c_sda = VL_RAND_RESET_I(1);
    io_i2c_scl = VL_RAND_RESET_I(1);
    io_ready = VL_RAND_RESET_I(1);
    io_stop = VL_RAND_RESET_I(1);
    io_i2c_intr = VL_RAND_RESET_I(1);
    i2c_master__DOT__state = VL_RAND_RESET_I(8);
    i2c_master__DOT__count = VL_RAND_RESET_I(15);
    i2c_master__DOT__saved_addr = VL_RAND_RESET_I(7);
    i2c_master__DOT__i2c_scl_enable = VL_RAND_RESET_I(1);
    i2c_master__DOT__intr_done = VL_RAND_RESET_I(1);
    i2c_master__DOT___GEN_5 = VL_RAND_RESET_I(15);
    i2c_master__DOT___GEN_43 = VL_RAND_RESET_I(15);
    i2c_master__DOT___GEN_44 = VL_RAND_RESET_I(1);
    i2c_master__DOT___GEN_61 = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
