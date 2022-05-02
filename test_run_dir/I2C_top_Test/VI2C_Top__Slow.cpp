// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VI2C_Top.h for the primary calling header

#include "VI2C_Top.h"
#include "VI2C_Top__Syms.h"

//==========

VI2C_Top::VI2C_Top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    VI2C_Top__Syms* __restrict vlSymsp = __VlSymsp = new VI2C_Top__Syms(_vcontextp__, this, name());
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VI2C_Top::__Vconfigure(VI2C_Top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

VI2C_Top::~VI2C_Top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VI2C_Top::_settle__TOP__2(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_settle__TOP__2\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_intr = vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done;
    vlTOPp->I2C_Top__DOT___GEN_12 = ((0x10U == (IData)(vlTOPp->io_addr))
                                      ? (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                      : ((8U == (IData)(vlTOPp->io_addr))
                                          ? (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                          : ((0xcU 
                                              == (IData)(vlTOPp->io_addr)) 
                                             & (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit))));
    vlTOPp->io_scl = (1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                            | (~ (IData)(vlTOPp->clock))));
    if ((0x10U == (IData)(vlTOPp->io_addr))) {
        vlTOPp->I2C_Top__DOT___GEN_9 = (0xffU & vlTOPp->io_wdata);
        vlTOPp->I2C_Top__DOT___GEN_10 = (1U & (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
    } else {
        vlTOPp->I2C_Top__DOT___GEN_9 = (0xffU & ((8U 
                                                  == (IData)(vlTOPp->io_addr))
                                                  ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                                  : 
                                                 ((0xcU 
                                                   == (IData)(vlTOPp->io_addr))
                                                   ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                                   : 0U)));
        vlTOPp->I2C_Top__DOT___GEN_10 = (1U & ((8U 
                                                == (IData)(vlTOPp->io_addr))
                                                ? vlTOPp->io_wdata
                                                : (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)));
    }
    vlTOPp->I2C_Top__DOT___GEN_28 = (1U & (((~ (IData)(vlTOPp->io_ren)) 
                                            & (IData)(vlTOPp->io_we))
                                            ? ((0U 
                                                == (IData)(vlTOPp->io_addr))
                                                ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                                                : (
                                                   (4U 
                                                    == (IData)(vlTOPp->io_addr))
                                                    ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                                                    : 
                                                   ((0x10U 
                                                     == (IData)(vlTOPp->io_addr))
                                                     ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                                                     : 
                                                    ((8U 
                                                      == (IData)(vlTOPp->io_addr))
                                                      ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                                                      : 
                                                     ((0xcU 
                                                       == (IData)(vlTOPp->io_addr))
                                                       ? vlTOPp->io_wdata
                                                       : (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in))))))
                                            : (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5 = 
        (0x7fffU & ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                     ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                     : ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count) 
                        - (IData)(1U))));
    vlTOPp->I2C_Top__DOT___GEN_13 = ((0x10U == (IData)(vlTOPp->io_addr))
                                      ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                      : ((8U == (IData)(vlTOPp->io_addr))
                                          ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                          : ((0xcU 
                                              == (IData)(vlTOPp->io_addr))
                                              ? (IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr)
                                              : 0U)));
    vlTOPp->io_ready = ((~ (IData)(vlTOPp->reset)) 
                        & ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                           & (1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))));
    vlTOPp->io_stop = ((~ (IData)(vlTOPp->reset)) & 
                       ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                        & ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                           & ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                              & ((3U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                 & ((4U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                    & ((5U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                       & ((6U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                          & (7U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))))))));
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
                                                    ((IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
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
    vlTOPp->io_sda = ((IData)(vlTOPp->reset) | ((0U 
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
                                                        == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                        ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                                        : 
                                                       ((4U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                         ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
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
                                                          | (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)))))))));
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_43 
        = ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
            ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5)
            : ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                : ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                    ? ((IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                        ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                        : 7U) : ((5U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                  ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5)
                                  : (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))));
}

void VI2C_Top::_eval_initial(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_eval_initial\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VI2C_Top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::final\n"); );
    // Variables
    VI2C_Top__Syms* __restrict vlSymsp = this->__VlSymsp;
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VI2C_Top::_eval_settle(VI2C_Top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_eval_settle\n"); );
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VI2C_Top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2C_Top::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_wdata = VL_RAND_RESET_I(32);
    io_addr = VL_RAND_RESET_I(7);
    io_ren = VL_RAND_RESET_I(1);
    io_we = VL_RAND_RESET_I(1);
    io_sda_in = VL_RAND_RESET_I(1);
    io_sda = VL_RAND_RESET_I(1);
    io_scl = VL_RAND_RESET_I(1);
    io_ready = VL_RAND_RESET_I(1);
    io_stop = VL_RAND_RESET_I(1);
    io_intr = VL_RAND_RESET_I(1);
    I2C_Top__DOT__addr_start_bit = VL_RAND_RESET_I(1);
    I2C_Top__DOT__addr_slave_addr = VL_RAND_RESET_I(7);
    I2C_Top__DOT__addr_data = VL_RAND_RESET_I(8);
    I2C_Top__DOT__addr_read_write_bit = VL_RAND_RESET_I(1);
    I2C_Top__DOT__addr_sda_in = VL_RAND_RESET_I(1);
    I2C_Top__DOT___GEN_9 = VL_RAND_RESET_I(8);
    I2C_Top__DOT___GEN_10 = VL_RAND_RESET_I(1);
    I2C_Top__DOT___GEN_12 = VL_RAND_RESET_I(1);
    I2C_Top__DOT___GEN_13 = VL_RAND_RESET_I(7);
    I2C_Top__DOT___GEN_28 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT__state = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_master__DOT__count = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT__saved_addr = VL_RAND_RESET_I(7);
    I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT__intr_done = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT___GEN_5 = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT___GEN_43 = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT___GEN_44 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT___GEN_61 = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
