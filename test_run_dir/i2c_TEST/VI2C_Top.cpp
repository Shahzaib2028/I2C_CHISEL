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
            VL_FATAL_MT("I2C_Top.v", 549, "",
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
            VL_FATAL_MT("I2C_Top.v", 549, "",
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
    // Variables
    CData/*7:0*/ __Vdly__I2C_Top__DOT__i2c_slave__DOT__count;
    // Body
    __Vdly__I2C_Top__DOT__i2c_slave__DOT__count = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count;
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_start_bit = 0U;
    } else {
        if (((~ (IData)(vlTOPp->io_ren)) & (IData)(vlTOPp->io_we))) {
            if ((0U == (IData)(vlTOPp->io_addr))) {
                vlTOPp->I2C_Top__DOT__addr_start_bit 
                    = (1U & vlTOPp->io_wdata);
            } else {
                if ((4U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_start_bit 
                        = vlTOPp->I2C_Top__DOT___GEN_6;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_data = 0U;
    } else {
        if (((~ (IData)(vlTOPp->io_ren)) & (IData)(vlTOPp->io_we))) {
            if ((0U != (IData)(vlTOPp->io_addr))) {
                if ((4U != (IData)(vlTOPp->io_addr))) {
                    vlTOPp->I2C_Top__DOT__addr_data 
                        = vlTOPp->I2C_Top__DOT___GEN_4;
                }
            }
        }
    }
    vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable 
        = (1U & ((IData)(vlTOPp->reset) | (~ (((0U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) 
                                              | (7U 
                                                 == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))));
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) {
                vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done = 0U;
            } else {
                if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) {
                    vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done 
                        = vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_44;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) {
                if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) {
                    vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr 
                        = vlTOPp->I2C_Top__DOT__addr_slave_addr;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_master__DOT__count = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->reset)))) {
            if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))) {
                vlTOPp->I2C_Top__DOT__i2c_master__DOT__count 
                    = ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                        ? 6U : (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_43));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_82;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_81;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_80;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_79;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_78;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_77;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_76;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_73;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__I2C_Top__DOT__i2c_slave__DOT__count = 1U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    __Vdly__I2C_Top__DOT__i2c_slave__DOT__count 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___count_T_1;
                }
            } else {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    __Vdly__I2C_Top__DOT__i2c_slave__DOT__count 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_74;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_1;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_4;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_7;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_10;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_13;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_16;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7 = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_19;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U <= (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___complete_addr_T;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
            if ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                if ((8U <= (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data = 0U;
                }
            } else {
                if ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
                    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data 
                        = vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_83;
                }
            }
        }
    }
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count = __Vdly__I2C_Top__DOT__i2c_slave__DOT__count;
    vlTOPp->io_intr = vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done;
    if (vlTOPp->reset) {
        vlTOPp->I2C_Top__DOT__addr_slave_addr = 0U;
    } else {
        if (((~ (IData)(vlTOPp->io_ren)) & (IData)(vlTOPp->io_we))) {
            if ((0U != (IData)(vlTOPp->io_addr))) {
                vlTOPp->I2C_Top__DOT__addr_slave_addr 
                    = (0x7fU & ((4U == (IData)(vlTOPp->io_addr))
                                 ? vlTOPp->io_wdata
                                 : (IData)(vlTOPp->I2C_Top__DOT___GEN_7)));
            }
        }
    }
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5 = 
        (0x7fffU & ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                     ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                     : ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count) 
                        - (IData)(1U))));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT__state = 
        ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_61));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___complete_addr_T 
        = (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1) 
            << 6U) | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2) 
                       << 5U) | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3) 
                                  << 4U) | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4) 
                                             << 3U) 
                                            | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5) 
                                                << 2U) 
                                               | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7)))))));
    vlTOPp->io_data_out = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data;
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___count_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_117));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_44 
        = ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
            ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)
            : ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)
                : ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)
                    : ((5U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                        ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)
                        : ((6U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                            ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)
                            : ((7U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                               | (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done)))))));
    if ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_74 
            = (0xffU & ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                         ? ((IData)(1U) + (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                         : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_83 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data)
                : (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1) 
                    << 7U) | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2) 
                               << 6U) | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3) 
                                          << 5U) | 
                                         (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4) 
                                           << 4U) | 
                                          (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5) 
                                            << 3U) 
                                           | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6) 
                                               << 2U) 
                                              | (((IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7) 
                                                  << 1U) 
                                                 | (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8)))))))));
    } else {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_74 
            = (0xffU & ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
                         ? 0U : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_83 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data;
    }
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_99 = 
        ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
          ? ((8U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
              ? ((7U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                  ? ((6U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                      ? ((5U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                          ? ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                              ? ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                  ? ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                      ? (((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                          & (1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)))
                                          ? 0U : 1U)
                                      : 1U) : 1U) : 1U)
                          : 1U) : 1U) : 1U) : 2U) : 
         ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
           ? ((0x63U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr))
               ? 3U : 4U) : ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
                              ? ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                  ? ((0xfU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                      ? ((0xeU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                          ? ((0xdU 
                                              == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                              ? ((0xcU 
                                                  == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                                  ? 
                                                 ((0xbU 
                                                   == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                                   ? 
                                                  ((0xaU 
                                                    == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                                    ? 
                                                   ((9U 
                                                     == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                                                     ? 
                                                    (((3U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                      & (8U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)))
                                                      ? 0U
                                                      : 3U)
                                                     : 3U)
                                                    : 3U)
                                                   : 3U)
                                                  : 3U)
                                              : 3U)
                                          : 3U) : 3U)
                                  : 4U) : 0U)));
    vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out = ((0U 
                                                   != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                  & ((1U 
                                                      != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                     & ((2U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                        & (0x63U 
                                                           != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr)))));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_43 
        = ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
            ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5)
            : ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                : ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                    ? ((IData)(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out)
                        ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                        : 7U) : ((5U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                  ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5)
                                  : (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))));
}

VL_INLINE_OPT void VI2C_Top::_combo__TOP__3(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_combo__TOP__3\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x10U == (IData)(vlTOPp->io_addr))) {
        vlTOPp->I2C_Top__DOT___GEN_6 = vlTOPp->I2C_Top__DOT__addr_start_bit;
        vlTOPp->I2C_Top__DOT___GEN_4 = (0xffU & vlTOPp->io_wdata);
    } else {
        vlTOPp->I2C_Top__DOT___GEN_6 = ((8U == (IData)(vlTOPp->io_addr)) 
                                        & (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit));
        vlTOPp->I2C_Top__DOT___GEN_4 = (0xffU & ((8U 
                                                  == (IData)(vlTOPp->io_addr))
                                                  ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                                  : 0U));
    }
    vlTOPp->io_scl = (1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                            | (~ (IData)(vlTOPp->clock))));
    vlTOPp->I2C_Top__DOT___GEN_7 = ((0x10U == (IData)(vlTOPp->io_addr))
                                     ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                     : ((8U == (IData)(vlTOPp->io_addr))
                                         ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                         : 0U));
    vlTOPp->io_stop = ((~ (IData)(vlTOPp->reset)) & 
                       ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                        & ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                           & ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                              & ((3U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                 & ((4U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                    & ((5U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                       & ((6U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                          & (7U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))))))));
    vlTOPp->I2C_Top__DOT__i2c_master_io_ready = ((~ (IData)(vlTOPp->reset)) 
                                                 & ((0U 
                                                     != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                    & (1U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_61 
        = ((IData)(vlTOPp->reset) ? 0U : ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                           ? ((IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                               ? 1U
                                               : 0U)
                                           : ((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                               ? 2U
                                               : ((2U 
                                                   == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                                    ? 3U
                                                    : 2U)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                    ? 4U
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                     ? 
                                                    ((IData)(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out)
                                                      ? 7U
                                                      : 5U)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                                       ? 6U
                                                       : 5U)
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                       ? 7U
                                                       : 0U))))))));
    vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda = ((IData)(vlTOPp->reset) 
                                                   | ((0U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                      | ((1U 
                                                          != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                         & ((2U 
                                                             == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                             ? 
                                                            ((6U 
                                                              >= (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                                              ? 
                                                             (0x7fU 
                                                              & ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr) 
                                                                 >> (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))
                                                              : 0U)
                                                             : 
                                                            ((3U 
                                                              != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                             & ((4U 
                                                                 == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                                 ? (IData)(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out)
                                                                 : 
                                                                ((5U 
                                                                  == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                                  ? 
                                                                 ((7U 
                                                                   >= (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                                                   ? 
                                                                  (0xffU 
                                                                   & ((IData)(vlTOPp->I2C_Top__DOT__addr_data) 
                                                                      >> (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))
                                                                   : 0U)
                                                                  : 
                                                                 ((6U 
                                                                   != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                                  | (IData)(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out)))))))));
    vlTOPp->io_ready = vlTOPp->I2C_Top__DOT__i2c_master_io_ready;
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_117 
        = ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
            ? ((IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_ready)
                ? 1U : 0U) : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_99));
    vlTOPp->io_sda = vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda;
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_4 = 
        ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_7 = 
        ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_10 = 
        ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_13 = 
        ((5U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_16 = 
        ((6U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_19 = 
        ((7U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7));
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_1 = 
        (((1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
          & (1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)))
          ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
          : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1));
    if ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))) {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_73 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? (((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                    & (8U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_76 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((9U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_77 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xaU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_78 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xbU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_79 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xcU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_80 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xdU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_81 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xeU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7));
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_82 
            = ((0x10U > (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                ? ((0xfU == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count))
                    ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda)
                    : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8))
                : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8));
    } else {
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_73 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_76 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_77 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_78 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_79 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_80 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_81 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7;
        vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_82 
            = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8;
    }
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
    if (VL_UNLIKELY((io_ren & 0xfeU))) {
        Verilated::overWidthError("io_ren");}
    if (VL_UNLIKELY((io_we & 0xfeU))) {
        Verilated::overWidthError("io_we");}
}
#endif  // VL_DEBUG
