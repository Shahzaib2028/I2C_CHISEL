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
            tracep->chgBit(oldp+3,(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out));
            tracep->chgBit(oldp+4,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done));
            tracep->chgCData(oldp+5,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data),8);
            tracep->chgCData(oldp+6,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state),8);
            tracep->chgSData(oldp+7,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count),15);
            tracep->chgCData(oldp+8,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr),7);
            tracep->chgBit(oldp+9,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable));
            tracep->chgCData(oldp+10,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count),8);
            tracep->chgCData(oldp+11,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state),8);
            tracep->chgBit(oldp+12,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1));
            tracep->chgBit(oldp+13,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2));
            tracep->chgBit(oldp+14,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3));
            tracep->chgBit(oldp+15,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4));
            tracep->chgBit(oldp+16,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5));
            tracep->chgBit(oldp+17,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6));
            tracep->chgBit(oldp+18,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7));
            tracep->chgCData(oldp+19,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr),7);
            tracep->chgBit(oldp+20,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1));
            tracep->chgBit(oldp+21,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2));
            tracep->chgBit(oldp+22,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3));
            tracep->chgBit(oldp+23,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4));
            tracep->chgBit(oldp+24,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5));
            tracep->chgBit(oldp+25,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6));
            tracep->chgBit(oldp+26,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7));
            tracep->chgBit(oldp+27,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8));
        }
        tracep->chgBit(oldp+28,(vlTOPp->clock));
        tracep->chgBit(oldp+29,(vlTOPp->reset));
        tracep->chgIData(oldp+30,(vlTOPp->io_wdata),32);
        tracep->chgCData(oldp+31,(vlTOPp->io_addr),7);
        tracep->chgBit(oldp+32,(vlTOPp->io_ren));
        tracep->chgBit(oldp+33,(vlTOPp->io_we));
        tracep->chgBit(oldp+34,(vlTOPp->io_sda));
        tracep->chgBit(oldp+35,(vlTOPp->io_scl));
        tracep->chgBit(oldp+36,(vlTOPp->io_ready));
        tracep->chgBit(oldp+37,(vlTOPp->io_stop));
        tracep->chgCData(oldp+38,(vlTOPp->io_data_out),8);
        tracep->chgBit(oldp+39,(vlTOPp->io_intr));
        tracep->chgBit(oldp+40,(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda));
        tracep->chgBit(oldp+41,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                                       | (~ (IData)(vlTOPp->clock))))));
        tracep->chgBit(oldp+42,(vlTOPp->I2C_Top__DOT__i2c_master_io_ready));
        tracep->chgBit(oldp+43,(((~ (IData)(vlTOPp->reset)) 
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
