// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2C_Top__Syms.h"


//======================

void VI2C_Top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VI2C_Top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VI2C_Top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VI2C_Top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VI2C_Top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+29,"clock", false,-1);
        tracep->declBit(c+30,"reset", false,-1);
        tracep->declBus(c+31,"io_wdata", false,-1, 31,0);
        tracep->declBus(c+32,"io_addr", false,-1, 6,0);
        tracep->declBit(c+33,"io_ren", false,-1);
        tracep->declBit(c+34,"io_we", false,-1);
        tracep->declBit(c+35,"io_sda", false,-1);
        tracep->declBit(c+36,"io_scl", false,-1);
        tracep->declBit(c+37,"io_ready", false,-1);
        tracep->declBit(c+38,"io_stop", false,-1);
        tracep->declBus(c+39,"io_data_out", false,-1, 7,0);
        tracep->declBit(c+40,"io_intr", false,-1);
        tracep->declBit(c+29,"I2C_Top clock", false,-1);
        tracep->declBit(c+30,"I2C_Top reset", false,-1);
        tracep->declBus(c+31,"I2C_Top io_wdata", false,-1, 31,0);
        tracep->declBus(c+32,"I2C_Top io_addr", false,-1, 6,0);
        tracep->declBit(c+33,"I2C_Top io_ren", false,-1);
        tracep->declBit(c+34,"I2C_Top io_we", false,-1);
        tracep->declBit(c+35,"I2C_Top io_sda", false,-1);
        tracep->declBit(c+36,"I2C_Top io_scl", false,-1);
        tracep->declBit(c+37,"I2C_Top io_ready", false,-1);
        tracep->declBit(c+38,"I2C_Top io_stop", false,-1);
        tracep->declBus(c+39,"I2C_Top io_data_out", false,-1, 7,0);
        tracep->declBit(c+40,"I2C_Top io_intr", false,-1);
        tracep->declBit(c+29,"I2C_Top i2c_master_clock", false,-1);
        tracep->declBit(c+30,"I2C_Top i2c_master_reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c_master_io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c_master_io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c_master_io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c_master_io_i2c_sda_in", false,-1);
        tracep->declBit(c+41,"I2C_Top i2c_master_io_i2c_sda", false,-1);
        tracep->declBit(c+42,"I2C_Top i2c_master_io_i2c_scl", false,-1);
        tracep->declBit(c+43,"I2C_Top i2c_master_io_ready", false,-1);
        tracep->declBit(c+44,"I2C_Top i2c_master_io_stop", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_master_io_i2c_intr", false,-1);
        tracep->declBit(c+29,"I2C_Top i2c_slave_clock", false,-1);
        tracep->declBit(c+30,"I2C_Top i2c_slave_reset", false,-1);
        tracep->declBit(c+41,"I2C_Top i2c_slave_io_sda_in", false,-1);
        tracep->declBit(c+43,"I2C_Top i2c_slave_io_ready", false,-1);
        tracep->declBit(c+4,"I2C_Top i2c_slave_io_sda_out", false,-1);
        tracep->declBus(c+6,"I2C_Top i2c_slave_io_data_out", false,-1, 7,0);
        tracep->declBit(c+1,"I2C_Top addr_start_bit", false,-1);
        tracep->declBus(c+2,"I2C_Top addr_slave_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top addr_data", false,-1, 7,0);
        tracep->declBit(c+29,"I2C_Top i2c_master clock", false,-1);
        tracep->declBit(c+30,"I2C_Top i2c_master reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c_master io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c_master io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c_master io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c_master io_i2c_sda_in", false,-1);
        tracep->declBit(c+41,"I2C_Top i2c_master io_i2c_sda", false,-1);
        tracep->declBit(c+42,"I2C_Top i2c_master io_i2c_scl", false,-1);
        tracep->declBit(c+43,"I2C_Top i2c_master io_ready", false,-1);
        tracep->declBit(c+44,"I2C_Top i2c_master io_stop", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_master io_i2c_intr", false,-1);
        tracep->declBus(c+7,"I2C_Top i2c_master state", false,-1, 7,0);
        tracep->declBus(c+8,"I2C_Top i2c_master count", false,-1, 14,0);
        tracep->declBus(c+9,"I2C_Top i2c_master saved_addr", false,-1, 6,0);
        tracep->declBit(c+10,"I2C_Top i2c_master i2c_scl_enable", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_master intr_done", false,-1);
        tracep->declBit(c+29,"I2C_Top i2c_slave clock", false,-1);
        tracep->declBit(c+30,"I2C_Top i2c_slave reset", false,-1);
        tracep->declBit(c+41,"I2C_Top i2c_slave io_sda_in", false,-1);
        tracep->declBit(c+43,"I2C_Top i2c_slave io_ready", false,-1);
        tracep->declBit(c+4,"I2C_Top i2c_slave io_sda_out", false,-1);
        tracep->declBus(c+6,"I2C_Top i2c_slave io_data_out", false,-1, 7,0);
        tracep->declBus(c+11,"I2C_Top i2c_slave count", false,-1, 7,0);
        tracep->declBus(c+12,"I2C_Top i2c_slave rx_state", false,-1, 7,0);
        tracep->declBit(c+13,"I2C_Top i2c_slave addr_bit1", false,-1);
        tracep->declBit(c+14,"I2C_Top i2c_slave addr_bit2", false,-1);
        tracep->declBit(c+15,"I2C_Top i2c_slave addr_bit3", false,-1);
        tracep->declBit(c+16,"I2C_Top i2c_slave addr_bit4", false,-1);
        tracep->declBit(c+17,"I2C_Top i2c_slave addr_bit5", false,-1);
        tracep->declBit(c+18,"I2C_Top i2c_slave addr_bit6", false,-1);
        tracep->declBit(c+19,"I2C_Top i2c_slave addr_bit7", false,-1);
        tracep->declBus(c+20,"I2C_Top i2c_slave complete_addr", false,-1, 6,0);
        tracep->declBit(c+21,"I2C_Top i2c_slave data_bit1", false,-1);
        tracep->declBit(c+22,"I2C_Top i2c_slave data_bit2", false,-1);
        tracep->declBit(c+23,"I2C_Top i2c_slave data_bit3", false,-1);
        tracep->declBit(c+24,"I2C_Top i2c_slave data_bit4", false,-1);
        tracep->declBit(c+25,"I2C_Top i2c_slave data_bit5", false,-1);
        tracep->declBit(c+26,"I2C_Top i2c_slave data_bit6", false,-1);
        tracep->declBit(c+27,"I2C_Top i2c_slave data_bit7", false,-1);
        tracep->declBit(c+28,"I2C_Top i2c_slave data_bit8", false,-1);
        tracep->declBus(c+6,"I2C_Top i2c_slave data", false,-1, 7,0);
    }
}

void VI2C_Top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VI2C_Top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VI2C_Top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VI2C_Top__Syms* __restrict vlSymsp = static_cast<VI2C_Top__Syms*>(userp);
    VI2C_Top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->I2C_Top__DOT__addr_start_bit));
        tracep->fullCData(oldp+2,(vlTOPp->I2C_Top__DOT__addr_slave_addr),7);
        tracep->fullCData(oldp+3,(vlTOPp->I2C_Top__DOT__addr_data),8);
        tracep->fullBit(oldp+4,(vlTOPp->I2C_Top__DOT__i2c_slave_io_sda_out));
        tracep->fullBit(oldp+5,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done));
        tracep->fullCData(oldp+6,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data),8);
        tracep->fullCData(oldp+7,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state),8);
        tracep->fullSData(oldp+8,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count),15);
        tracep->fullCData(oldp+9,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr),7);
        tracep->fullBit(oldp+10,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable));
        tracep->fullCData(oldp+11,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__count),8);
        tracep->fullCData(oldp+12,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__rx_state),8);
        tracep->fullBit(oldp+13,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit1));
        tracep->fullBit(oldp+14,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit2));
        tracep->fullBit(oldp+15,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit3));
        tracep->fullBit(oldp+16,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit4));
        tracep->fullBit(oldp+17,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit5));
        tracep->fullBit(oldp+18,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit6));
        tracep->fullBit(oldp+19,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__addr_bit7));
        tracep->fullCData(oldp+20,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__complete_addr),7);
        tracep->fullBit(oldp+21,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit1));
        tracep->fullBit(oldp+22,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit2));
        tracep->fullBit(oldp+23,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit3));
        tracep->fullBit(oldp+24,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit4));
        tracep->fullBit(oldp+25,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit5));
        tracep->fullBit(oldp+26,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit6));
        tracep->fullBit(oldp+27,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit7));
        tracep->fullBit(oldp+28,(vlTOPp->I2C_Top__DOT__i2c_slave__DOT__data_bit8));
        tracep->fullBit(oldp+29,(vlTOPp->clock));
        tracep->fullBit(oldp+30,(vlTOPp->reset));
        tracep->fullIData(oldp+31,(vlTOPp->io_wdata),32);
        tracep->fullCData(oldp+32,(vlTOPp->io_addr),7);
        tracep->fullBit(oldp+33,(vlTOPp->io_ren));
        tracep->fullBit(oldp+34,(vlTOPp->io_we));
        tracep->fullBit(oldp+35,(vlTOPp->io_sda));
        tracep->fullBit(oldp+36,(vlTOPp->io_scl));
        tracep->fullBit(oldp+37,(vlTOPp->io_ready));
        tracep->fullBit(oldp+38,(vlTOPp->io_stop));
        tracep->fullCData(oldp+39,(vlTOPp->io_data_out),8);
        tracep->fullBit(oldp+40,(vlTOPp->io_intr));
        tracep->fullBit(oldp+41,(vlTOPp->I2C_Top__DOT__i2c_master_io_i2c_sda));
        tracep->fullBit(oldp+42,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                                        | (~ (IData)(vlTOPp->clock))))));
        tracep->fullBit(oldp+43,(vlTOPp->I2C_Top__DOT__i2c_master_io_ready));
        tracep->fullBit(oldp+44,(((~ (IData)(vlTOPp->reset)) 
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
