// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VI2C_Top.h for the primary calling header

#include "VI2C_Top.h"
#include "VI2C_Top__Syms.h"

//==========

VerilatedContext* VI2C_Top::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void VI2C_Top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VI2C_Top::eval\n"); );
    VI2C_Top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("I2C_Top.v", 125, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VI2C_Top::_eval_initial_loop(VI2C_Top__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("I2C_Top.v", 125, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VI2C_Top::_sequent__TOP__1(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_sequent__TOP__1\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_start_bit = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->io_addr))) {
            vlTOPp->I2C_Top__DOT__addr_start_bit = 
                (1U & vlTOPp->io_wdata);
        } else {
            if ((4U != (IData)(vlTOPp->io_addr))) {
                if ((0x10U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_start_bit 
                        = vlTOPp->I2C_Top__DOT___GEN_12;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_data = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->io_addr))) {
            if ((4U != (IData)(vlTOPp->io_addr))) {
                vlTOPp->I2C_Top__DOT__addr_data = (0xffU 
                                                   & ((0x10U 
                                                       == (IData)(vlTOPp->io_addr))
                                                       ? vlTOPp->io_wdata
                                                       : (IData)(vlTOPp->I2C_Top__DOT___GEN_14)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_slave_addr = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->io_addr))) {
            if ((4U == (IData)(vlTOPp->io_addr))) {
                vlTOPp->I2C_Top__DOT__addr_slave_addr 
                    = (0x7fU & vlTOPp->io_wdata);
            } else {
                if ((0x10U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_slave_addr 
                        = vlTOPp->I2C_Top__DOT___GEN_13;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_data_ack = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->io_addr))) {
            if ((4U != (IData)(vlTOPp->io_addr))) {
                if ((0x10U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_data_ack 
                        = vlTOPp->I2C_Top__DOT___GEN_11;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_read_write_bit = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->io_addr))) {
            if ((4U != (IData)(vlTOPp->io_addr))) {
                if ((0x10U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_read_write_bit 
                        = vlTOPp->I2C_Top__DOT___GEN_9;
                }
            }
        }
    }
    vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable 
        = (1U & ((IData)(vlTOPp->reset) | (~ (((0U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))) 
                                              | (6U 
                                                 == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))))));
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c__DOT__count = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))) {
                vlTOPp->I2C_Top__DOT__i2c__DOT__count 
                    = ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                        ? 6U : (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_29));
            }
        }
    }
    vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_5 = (0x7fffU 
                                              & ((0U 
                                                  == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                  ? (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)
                                                  : 
                                                 ((IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count) 
                                                  - (IData)(1U))));
    vlTOPp->I2C_Top__DOT__i2c__DOT__state = ((IData)(vlTOPp->reset)
                                              ? 0U : (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_40));
    vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_29 = ((2U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                ? (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_5)
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                    ? 
                                                   ((IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                                     ? 7U
                                                     : 8U)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                     ? (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_5)
                                                     : (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))));
}

VL_INLINE_OPT void VI2C_Top::_combo__TOP__3(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_combo__TOP__3\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((8U == (IData)(vlTOPp->io_addr))) {
        vlTOPp->I2C_Top__DOT___GEN_12 = vlTOPp->I2C_Top__DOT__addr_start_bit;
        vlTOPp->I2C_Top__DOT___GEN_14 = vlTOPp->I2C_Top__DOT__addr_data;
        vlTOPp->I2C_Top__DOT___GEN_13 = vlTOPp->I2C_Top__DOT__addr_slave_addr;
        vlTOPp->I2C_Top__DOT___GEN_11 = (1U & (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack));
        vlTOPp->I2C_Top__DOT___GEN_9 = (1U & vlTOPp->io_wdata);
    } else {
        vlTOPp->I2C_Top__DOT___GEN_12 = ((0xcU == (IData)(vlTOPp->io_addr))
                                          ? (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                          : ((0x14U 
                                              == (IData)(vlTOPp->io_addr)) 
                                             & (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)));
        vlTOPp->I2C_Top__DOT___GEN_14 = ((0xcU == (IData)(vlTOPp->io_addr))
                                          ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                          : ((0x14U 
                                              == (IData)(vlTOPp->io_addr))
                                              ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                              : 0U));
        vlTOPp->I2C_Top__DOT___GEN_13 = ((0xcU == (IData)(vlTOPp->io_addr))
                                          ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                          : ((0x14U 
                                              == (IData)(vlTOPp->io_addr))
                                              ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                              : 0U));
        vlTOPp->I2C_Top__DOT___GEN_11 = (1U & ((0xcU 
                                                == (IData)(vlTOPp->io_addr))
                                                ? (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack)
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlTOPp->io_addr))
                                                    ? vlTOPp->io_wdata
                                                    : (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack))));
        vlTOPp->I2C_Top__DOT___GEN_9 = (1U & (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
    }
    vlTOPp->io_scl = (1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable)) 
                            | (~ (IData)(vlTOPp->clock))));
    vlTOPp->I2C_Top__DOT__i2c__DOT___GEN_40 = ((IData)(vlTOPp->reset)
                                                ? 0U
                                                : (
                                                   (0U 
                                                    == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                    ? 
                                                   ((IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                     ? 2U
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                       ? 3U
                                                       : 2U)
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                       ? 4U
                                                       : 
                                                      ((4U 
                                                        == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                        ? 
                                                       ((0U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                         ? 5U
                                                         : 4U)
                                                        : 
                                                       ((5U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                         ? 6U
                                                         : 0U)))))));
    vlTOPp->io_sda = ((IData)(vlTOPp->reset) | ((0U 
                                                 == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                                | ((1U 
                                                    != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                                   & ((2U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                       ? 
                                                      ((6U 
                                                        >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                        ? 
                                                       (0x7fU 
                                                        & ((IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr) 
                                                           >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                                        : 0U)
                                                       : 
                                                      ((3U 
                                                        == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                        ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                                        : 
                                                       ((4U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                         ? 
                                                        ((7U 
                                                          >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                          ? 
                                                         (0xffU 
                                                          & ((IData)(vlTOPp->I2C_Top__DOT__addr_data) 
                                                             >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                                          : 0U)
                                                         : 
                                                        ((5U 
                                                          != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                                         | (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack))))))));
}

void VI2C_Top::_eval(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_eval\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VI2C_Top::_change_request(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_change_request\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VI2C_Top::_change_request_1(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_change_request_1\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VI2C_Top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_addr & 0x80U))) {
        Verilated::overWidthError("io_addr");}
}
#endif  // VL_DEBUG
