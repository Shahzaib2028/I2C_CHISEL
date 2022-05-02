// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2c_master.h for the primary calling header

#include "Vi2c_master.h"
#include "Vi2c_master__Syms.h"

//==========

VerilatedContext* Vi2c_master::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vi2c_master::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2c_master::eval\n"); );
    Vi2c_master__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("i2c_master.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vi2c_master::_eval_initial_loop(Vi2c_master__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("i2c_master.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vi2c_master::_sequent__TOP__1(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_sequent__TOP__1\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2c_master__DOT__i2c_scl_enable = (1U & 
                                               ((IData)(vlTOPp->reset) 
                                                | (~ 
                                                   (((0U 
                                                      == (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->i2c_master__DOT__state))) 
                                                    | (7U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__state))))));
    if (vlTOPp->reset) {
        vlTOPp->i2c_master__DOT__saved_addr = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->i2c_master__DOT__state))) {
                if ((1U == (IData)(vlTOPp->i2c_master__DOT__state))) {
                    vlTOPp->i2c_master__DOT__saved_addr 
                        = vlTOPp->io_addr;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->i2c_master__DOT__intr_done = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U == (IData)(vlTOPp->i2c_master__DOT__state))) {
                vlTOPp->i2c_master__DOT__intr_done = 0U;
            } else {
                if ((1U != (IData)(vlTOPp->i2c_master__DOT__state))) {
                    vlTOPp->i2c_master__DOT__intr_done 
                        = vlTOPp->i2c_master__DOT___GEN_44;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->i2c_master__DOT__count = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->i2c_master__DOT__state))) {
                vlTOPp->i2c_master__DOT__count = ((1U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__state))
                                                   ? 6U
                                                   : (IData)(vlTOPp->i2c_master__DOT___GEN_43));
            }
        }
    }
    vlTOPp->io_i2c_intr = vlTOPp->i2c_master__DOT__intr_done;
    vlTOPp->i2c_master__DOT___GEN_5 = (0x7fffU & ((0U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__count))
                                                   ? (IData)(vlTOPp->i2c_master__DOT__count)
                                                   : 
                                                  ((IData)(vlTOPp->i2c_master__DOT__count) 
                                                   - (IData)(1U))));
    vlTOPp->i2c_master__DOT__state = ((IData)(vlTOPp->reset)
                                       ? 0U : (IData)(vlTOPp->i2c_master__DOT___GEN_61));
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
}

VL_INLINE_OPT void Vi2c_master::_combo__TOP__3(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_combo__TOP__3\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_scl = (1U & ((~ (IData)(vlTOPp->i2c_master__DOT__i2c_scl_enable)) 
                                | (~ (IData)(vlTOPp->clock))));
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
}

void Vi2c_master::_eval(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData Vi2c_master::_change_request(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_change_request\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vi2c_master::_change_request_1(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_change_request_1\n"); );
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vi2c_master::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_start & 0xfeU))) {
        Verilated::overWidthError("io_start");}
    if (VL_UNLIKELY((io_addr & 0x80U))) {
        Verilated::overWidthError("io_addr");}
    if (VL_UNLIKELY((io_read_write & 0xfeU))) {
        Verilated::overWidthError("io_read_write");}
    if (VL_UNLIKELY((io_i2c_sda_in & 0xfeU))) {
        Verilated::overWidthError("io_i2c_sda_in");}
}
#endif  // VL_DEBUG
