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
        tracep->declBit(c+11,"clock", false,-1);
        tracep->declBit(c+12,"reset", false,-1);
        tracep->declBus(c+13,"io_wdata", false,-1, 31,0);
        tracep->declBus(c+14,"io_addr", false,-1, 6,0);
        tracep->declBit(c+15,"io_ren", false,-1);
        tracep->declBit(c+16,"io_we", false,-1);
        tracep->declBit(c+17,"io_sda_in", false,-1);
        tracep->declBit(c+18,"io_sda", false,-1);
        tracep->declBit(c+19,"io_scl", false,-1);
        tracep->declBit(c+20,"io_ready", false,-1);
        tracep->declBit(c+21,"io_stop", false,-1);
        tracep->declBit(c+22,"io_intr", false,-1);
        tracep->declBit(c+11,"I2C_Top clock", false,-1);
        tracep->declBit(c+12,"I2C_Top reset", false,-1);
        tracep->declBus(c+13,"I2C_Top io_wdata", false,-1, 31,0);
        tracep->declBus(c+14,"I2C_Top io_addr", false,-1, 6,0);
        tracep->declBit(c+15,"I2C_Top io_ren", false,-1);
        tracep->declBit(c+16,"I2C_Top io_we", false,-1);
        tracep->declBit(c+17,"I2C_Top io_sda_in", false,-1);
        tracep->declBit(c+18,"I2C_Top io_sda", false,-1);
        tracep->declBit(c+19,"I2C_Top io_scl", false,-1);
        tracep->declBit(c+20,"I2C_Top io_ready", false,-1);
        tracep->declBit(c+21,"I2C_Top io_stop", false,-1);
        tracep->declBit(c+22,"I2C_Top io_intr", false,-1);
        tracep->declBit(c+11,"I2C_Top i2c_master_clock", false,-1);
        tracep->declBit(c+12,"I2C_Top i2c_master_reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c_master_io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c_master_io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c_master_io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c_master_io_read_write", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_master_io_i2c_sda_in", false,-1);
        tracep->declBit(c+23,"I2C_Top i2c_master_io_i2c_sda", false,-1);
        tracep->declBit(c+24,"I2C_Top i2c_master_io_i2c_scl", false,-1);
        tracep->declBit(c+25,"I2C_Top i2c_master_io_ready", false,-1);
        tracep->declBit(c+26,"I2C_Top i2c_master_io_stop", false,-1);
        tracep->declBit(c+6,"I2C_Top i2c_master_io_i2c_intr", false,-1);
        tracep->declBit(c+1,"I2C_Top addr_start_bit", false,-1);
        tracep->declBus(c+2,"I2C_Top addr_slave_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top addr_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top addr_read_write_bit", false,-1);
        tracep->declBit(c+5,"I2C_Top addr_sda_in", false,-1);
        tracep->declBit(c+11,"I2C_Top i2c_master clock", false,-1);
        tracep->declBit(c+12,"I2C_Top i2c_master reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c_master io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c_master io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c_master io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c_master io_read_write", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_master io_i2c_sda_in", false,-1);
        tracep->declBit(c+23,"I2C_Top i2c_master io_i2c_sda", false,-1);
        tracep->declBit(c+24,"I2C_Top i2c_master io_i2c_scl", false,-1);
        tracep->declBit(c+25,"I2C_Top i2c_master io_ready", false,-1);
        tracep->declBit(c+26,"I2C_Top i2c_master io_stop", false,-1);
        tracep->declBit(c+6,"I2C_Top i2c_master io_i2c_intr", false,-1);
        tracep->declBus(c+7,"I2C_Top i2c_master state", false,-1, 7,0);
        tracep->declBus(c+8,"I2C_Top i2c_master count", false,-1, 14,0);
        tracep->declBus(c+9,"I2C_Top i2c_master saved_addr", false,-1, 6,0);
        tracep->declBit(c+10,"I2C_Top i2c_master i2c_scl_enable", false,-1);
        tracep->declBit(c+6,"I2C_Top i2c_master intr_done", false,-1);
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
        tracep->fullBit(oldp+4,(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
        tracep->fullBit(oldp+5,(vlTOPp->I2C_Top__DOT__addr_sda_in));
        tracep->fullBit(oldp+6,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__intr_done));
        tracep->fullCData(oldp+7,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state),8);
        tracep->fullSData(oldp+8,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count),15);
        tracep->fullCData(oldp+9,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr),7);
        tracep->fullBit(oldp+10,(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable));
        tracep->fullBit(oldp+11,(vlTOPp->clock));
        tracep->fullBit(oldp+12,(vlTOPp->reset));
        tracep->fullIData(oldp+13,(vlTOPp->io_wdata),32);
        tracep->fullCData(oldp+14,(vlTOPp->io_addr),7);
        tracep->fullBit(oldp+15,(vlTOPp->io_ren));
        tracep->fullBit(oldp+16,(vlTOPp->io_we));
        tracep->fullBit(oldp+17,(vlTOPp->io_sda_in));
        tracep->fullBit(oldp+18,(vlTOPp->io_sda));
        tracep->fullBit(oldp+19,(vlTOPp->io_scl));
        tracep->fullBit(oldp+20,(vlTOPp->io_ready));
        tracep->fullBit(oldp+21,(vlTOPp->io_stop));
        tracep->fullBit(oldp+22,(vlTOPp->io_intr));
        tracep->fullBit(oldp+23,(((IData)(vlTOPp->reset) 
                                  | ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                     | ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                        & ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                            ? ((6U 
                                                >= (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count))
                                                ? (0x7fU 
                                                   & ((IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__saved_addr) 
                                                      >> (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__count)))
                                                : 0U)
                                            : ((3U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))
                                                ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                                : (
                                                   (4U 
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
        tracep->fullBit(oldp+24,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__i2c_scl_enable)) 
                                        | (~ (IData)(vlTOPp->clock))))));
        tracep->fullBit(oldp+25,(((~ (IData)(vlTOPp->reset)) 
                                  & ((0U != (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state)) 
                                     & (1U == (IData)(vlTOPp->I2C_Top__DOT__i2c_master__DOT__state))))));
        tracep->fullBit(oldp+26,(((~ (IData)(vlTOPp->reset)) 
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
