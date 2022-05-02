// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2C_Top__Syms.h"


void VI2C_Top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VI2C_Top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->I2C_Top__DOT__addr_start_bit));
            tracep->chgCData(oldp+1,(vlTOPp->I2C_Top__DOT__addr_slave_addr),7);
            tracep->chgCData(oldp+2,(vlTOPp->I2C_Top__DOT__addr_data),8);
            tracep->chgBit(oldp+3,(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
            tracep->chgBit(oldp+4,(vlTOPp->I2C_Top__DOT__addr_sda_in));
            tracep->chgBit(oldp+5,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done));
            tracep->chgCData(oldp+6,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state),8);
            tracep->chgSData(oldp+7,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count),15);
            tracep->chgCData(oldp+8,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr),7);
            tracep->chgBit(oldp+9,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable));
        }
        tracep->chgBit(oldp+10,(vlTOPp->clock));
        tracep->chgBit(oldp+11,(vlTOPp->reset));
        tracep->chgIData(oldp+12,(vlTOPp->io_wdata),32);
        tracep->chgCData(oldp+13,(vlTOPp->io_addr),7);
        tracep->chgBit(oldp+14,(vlTOPp->io_ren));
        tracep->chgBit(oldp+15,(vlTOPp->io_we));
        tracep->chgBit(oldp+16,(vlTOPp->io_sda_in));
        tracep->chgBit(oldp+17,(vlTOPp->io_sda));
        tracep->chgBit(oldp+18,(vlTOPp->io_scl));
        tracep->chgBit(oldp+19,(vlTOPp->io_ready));
        tracep->chgBit(oldp+20,(vlTOPp->io_stop));
        tracep->chgBit(oldp+21,(vlTOPp->io_intr));
        tracep->chgBit(oldp+22,(((IData)(vlTOPp->reset) 
                                 | ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                    | ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                       & ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                           ? ((6U >= (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                               ? (0x7fU 
                                                  & ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr) 
                                                     >> (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))
                                               : 0U)
                                           : ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                               ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                               : ((4U 
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
                                                    | (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)))))))))));
        tracep->chgBit(oldp+23,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                                       | (~ (IData)(vlTOPp->clock))))));
        tracep->chgBit(oldp+24,(((~ (IData)(vlTOPp->reset)) 
                                 & ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                    & (1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))));
        tracep->chgBit(oldp+25,(((~ (IData)(vlTOPp->reset)) 
                                 & ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                    & ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                       & ((2U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                          & ((3U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                             & ((4U 
                                                 != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                & ((5U 
                                                    != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                   & ((6U 
                                                       != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                                      & (7U 
                                                         == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))))))))));
    }
}

void VI2C_Top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
