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
    vlTOPp->io_data_out = vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data;
    vlTOPp->io_intr = vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done;
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___count_T_1 
        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count)));
    vlTOPp->I2C_Top__DOT___GEN_6 = ((0x10U == (IData)(vlTOPp->io_addr))
                                     ? (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)
                                     : ((8U == (IData)(vlTOPp->io_addr)) 
                                        & (IData)(vlTOPp->I2C_Top__DOT__addr_start_bit)));
    vlTOPp->io_scl = (1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                            | (~ (IData)(vlTOPp->clock))));
    vlTOPp->I2C_Top__DOT___GEN_4 = (0xffU & ((0x10U 
                                              == (IData)(vlTOPp->io_addr))
                                              ? vlTOPp->io_wdata
                                              : ((8U 
                                                  == (IData)(vlTOPp->io_addr))
                                                  ? (IData)(vlTOPp->I2C_Top__DOT__addr_data)
                                                  : 0U)));
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
    vlTOPp->I2C_Top__DOT__i2c_master__DOT___GEN_5 = 
        (0x7fffU & ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                     ? (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)
                     : ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count) 
                        - (IData)(1U))));
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
    vlTOPp->I2C_Top__DOT__i2c_master_io_ready = ((~ (IData)(vlTOPp->reset)) 
                                                 & ((0U 
                                                     != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                    & (1U 
                                                       == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))));
    vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out = ((0U 
                                                   != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                  & ((1U 
                                                      != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                     & ((2U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state)) 
                                                        & (0x63U 
                                                           != (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr)))));
    vlTOPp->io_ready = vlTOPp->I2C_Top__DOT__i2c_master_io_ready;
    vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_117 
        = ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state))
            ? ((IData)(vlTOPp->I2C_Top__DOT__i2c_master_io_ready)
                ? 1U : 0U) : (IData)(vlTOPp->I2C_Top__DOT__i2c_slave__DOT___GEN_99));
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
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
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
    io_sda = VL_RAND_RESET_I(1);
    io_scl = VL_RAND_RESET_I(1);
    io_ready = VL_RAND_RESET_I(1);
    io_stop = VL_RAND_RESET_I(1);
    io_data_out = VL_RAND_RESET_I(8);
    io_intr = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master_io_i2c_sda = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master_io_ready = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave_io_sda_out = VL_RAND_RESET_I(1);
    I2C_Top__DOT__addr_start_bit = VL_RAND_RESET_I(1);
    I2C_Top__DOT__addr_slave_addr = VL_RAND_RESET_I(7);
    I2C_Top__DOT__addr_data = VL_RAND_RESET_I(8);
    I2C_Top__DOT___GEN_4 = VL_RAND_RESET_I(8);
    I2C_Top__DOT___GEN_6 = VL_RAND_RESET_I(1);
    I2C_Top__DOT___GEN_7 = VL_RAND_RESET_I(7);
    I2C_Top__DOT__i2c_master__DOT__state = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_master__DOT__count = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT__saved_addr = VL_RAND_RESET_I(7);
    I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT__intr_done = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT___GEN_5 = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT___GEN_43 = VL_RAND_RESET_I(15);
    I2C_Top__DOT__i2c_master__DOT___GEN_44 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_master__DOT___GEN_61 = VL_RAND_RESET_I(3);
    I2C_Top__DOT__i2c_slave__DOT__count = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT__rx_state = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit1 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit2 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit3 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit4 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit5 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit6 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__addr_bit7 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__complete_addr = VL_RAND_RESET_I(7);
    I2C_Top__DOT__i2c_slave__DOT__data_bit1 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit2 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit3 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit4 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit5 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit6 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit7 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data_bit8 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT__data = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT___count_T_1 = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT___GEN_1 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_4 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_7 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_10 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_13 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_16 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_19 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___complete_addr_T = VL_RAND_RESET_I(7);
    I2C_Top__DOT__i2c_slave__DOT___GEN_73 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_74 = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT___GEN_76 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_77 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_78 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_79 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_80 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_81 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_82 = VL_RAND_RESET_I(1);
    I2C_Top__DOT__i2c_slave__DOT___GEN_83 = VL_RAND_RESET_I(8);
    I2C_Top__DOT__i2c_slave__DOT___GEN_99 = VL_RAND_RESET_I(3);
    I2C_Top__DOT__i2c_slave__DOT___GEN_117 = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
