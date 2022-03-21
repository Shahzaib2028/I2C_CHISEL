// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2c_master.h for the primary calling header

#include "Vi2c_master.h"
#include "Vi2c_master__Syms.h"

//==========

VL_CTOR_IMP(Vi2c_master) {
    Vi2c_master__Syms* __restrict vlSymsp = __VlSymsp = new Vi2c_master__Syms(this, name());
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vi2c_master::__Vconfigure(Vi2c_master__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vi2c_master::~Vi2c_master() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vi2c_master::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2c_master::eval\n"); );
    Vi2c_master__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vi2c_master::_initial__TOP__1(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_initial__TOP__1\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_stop = 0U;
}

VL_INLINE_OPT void Vi2c_master::_sequent__TOP__2(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_sequent__TOP__2\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2c_master__DOT__i2c_scl_enable = (1U & 
                                               ((IData)(vlTOPp->reset) 
                                                | (~ 
                                                   (((0U 
                                                      == (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->i2c_master__DOT__state))) 
                                                    | (6U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__state))))));
    if (vlTOPp->reset) {
        vlTOPp->i2c_master__DOT__saved_data = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->i2c_master__DOT__state))) {
                if ((1U == (IData)(vlTOPp->i2c_master__DOT__state))) {
                    vlTOPp->i2c_master__DOT__saved_data 
                        = vlTOPp->io_data;
                }
            }
        }
    }
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
        vlTOPp->i2c_master__DOT__count = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->i2c_master__DOT__state))) {
                vlTOPp->i2c_master__DOT__count = ((1U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__state))
                                                   ? 6U
                                                   : (IData)(vlTOPp->i2c_master__DOT___GEN_29));
            }
        }
    }
    vlTOPp->i2c_master__DOT___GEN_5 = (0x7fffU & ((0U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__count))
                                                   ? (IData)(vlTOPp->i2c_master__DOT__count)
                                                   : 
                                                  ((IData)(vlTOPp->i2c_master__DOT__count) 
                                                   - (IData)(1U))));
    vlTOPp->i2c_master__DOT__state = ((IData)(vlTOPp->reset)
                                       ? 0U : (IData)(vlTOPp->i2c_master__DOT___GEN_44));
}

void Vi2c_master::_settle__TOP__3(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_settle__TOP__3\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_scl = (1U & ((~ (IData)(vlTOPp->i2c_master__DOT__i2c_scl_enable)) 
                                | (~ (IData)(vlTOPp->clock))));
    vlTOPp->i2c_master__DOT___GEN_5 = (0x7fffU & ((0U 
                                                   == (IData)(vlTOPp->i2c_master__DOT__count))
                                                   ? (IData)(vlTOPp->i2c_master__DOT__count)
                                                   : 
                                                  ((IData)(vlTOPp->i2c_master__DOT__count) 
                                                   - (IData)(1U))));
    vlTOPp->io_ready = ((~ (IData)(vlTOPp->reset)) 
                        & ((0U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                           & (1U == (IData)(vlTOPp->i2c_master__DOT__state))));
    vlTOPp->i2c_master__DOT___GEN_44 = ((IData)(vlTOPp->reset)
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
                                                     ((0U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__count))
                                                       ? 5U
                                                       : 4U)
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__state))
                                                       ? 6U
                                                       : 0U)))))));
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
                                                    ? 
                                                   ((7U 
                                                     >= (IData)(vlTOPp->i2c_master__DOT__count))
                                                     ? 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->i2c_master__DOT__saved_data) 
                                                        >> (IData)(vlTOPp->i2c_master__DOT__count)))
                                                     : 0U)
                                                    : 
                                                   ((5U 
                                                     != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                    | (IData)(vlTOPp->io_data_ack))))))));
    vlTOPp->i2c_master__DOT___GEN_29 = ((2U == (IData)(vlTOPp->i2c_master__DOT__state))
                                         ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                         : ((3U == (IData)(vlTOPp->i2c_master__DOT__state))
                                             ? ((IData)(vlTOPp->io_read_write)
                                                 ? 7U
                                                 : 8U)
                                             : ((4U 
                                                 == (IData)(vlTOPp->i2c_master__DOT__state))
                                                 ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                                 : (IData)(vlTOPp->i2c_master__DOT__count))));
}

VL_INLINE_OPT void Vi2c_master::_combo__TOP__4(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_combo__TOP__4\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_scl = (1U & ((~ (IData)(vlTOPp->i2c_master__DOT__i2c_scl_enable)) 
                                | (~ (IData)(vlTOPp->clock))));
    vlTOPp->io_ready = ((~ (IData)(vlTOPp->reset)) 
                        & ((0U != (IData)(vlTOPp->i2c_master__DOT__state)) 
                           & (1U == (IData)(vlTOPp->i2c_master__DOT__state))));
    vlTOPp->i2c_master__DOT___GEN_29 = ((2U == (IData)(vlTOPp->i2c_master__DOT__state))
                                         ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                         : ((3U == (IData)(vlTOPp->i2c_master__DOT__state))
                                             ? ((IData)(vlTOPp->io_read_write)
                                                 ? 7U
                                                 : 8U)
                                             : ((4U 
                                                 == (IData)(vlTOPp->i2c_master__DOT__state))
                                                 ? (IData)(vlTOPp->i2c_master__DOT___GEN_5)
                                                 : (IData)(vlTOPp->i2c_master__DOT__count))));
    vlTOPp->i2c_master__DOT___GEN_44 = ((IData)(vlTOPp->reset)
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
                                                     ((0U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__count))
                                                       ? 5U
                                                       : 4U)
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->i2c_master__DOT__state))
                                                       ? 6U
                                                       : 0U)))))));
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
                                                    ? 
                                                   ((7U 
                                                     >= (IData)(vlTOPp->i2c_master__DOT__count))
                                                     ? 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->i2c_master__DOT__saved_data) 
                                                        >> (IData)(vlTOPp->i2c_master__DOT__count)))
                                                     : 0U)
                                                    : 
                                                   ((5U 
                                                     != (IData)(vlTOPp->i2c_master__DOT__state)) 
                                                    | (IData)(vlTOPp->io_data_ack))))))));
}

void Vi2c_master::_eval(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vi2c_master::_eval_initial(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval_initial\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vi2c_master::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::final\n"); );
    // Variables
    Vi2c_master__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vi2c_master::_eval_settle(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_eval_settle\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vi2c_master::_change_request(Vi2c_master__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_change_request\n"); );
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
    if (VL_UNLIKELY((io_ack & 0xfeU))) {
        Verilated::overWidthError("io_ack");}
    if (VL_UNLIKELY((io_data_ack & 0xfeU))) {
        Verilated::overWidthError("io_data_ack");}
}
#endif  // VL_DEBUG

void Vi2c_master::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2c_master::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_start = VL_RAND_RESET_I(1);
    io_addr = VL_RAND_RESET_I(7);
    io_data = VL_RAND_RESET_I(8);
    io_read_write = VL_RAND_RESET_I(1);
    io_ack = VL_RAND_RESET_I(1);
    io_data_ack = VL_RAND_RESET_I(1);
    io_i2c_sda = VL_RAND_RESET_I(1);
    io_i2c_scl = VL_RAND_RESET_I(1);
    io_ready = VL_RAND_RESET_I(1);
    io_stop = VL_RAND_RESET_I(1);
    i2c_master__DOT__state = VL_RAND_RESET_I(8);
    i2c_master__DOT__count = VL_RAND_RESET_I(15);
    i2c_master__DOT__saved_addr = VL_RAND_RESET_I(7);
    i2c_master__DOT__saved_data = VL_RAND_RESET_I(8);
    i2c_master__DOT__i2c_scl_enable = VL_RAND_RESET_I(1);
    i2c_master__DOT___GEN_5 = VL_RAND_RESET_I(15);
    i2c_master__DOT___GEN_29 = VL_RAND_RESET_I(15);
    i2c_master__DOT___GEN_44 = VL_RAND_RESET_I(3);
    __Vm_traceActivity = 0;
}
