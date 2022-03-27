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
        tracep->declBit(c+9,"clock", false,-1);
        tracep->declBit(c+10,"reset", false,-1);
        tracep->declBus(c+11,"io_wdata", false,-1, 31,0);
        tracep->declBus(c+12,"io_addr", false,-1, 6,0);
        tracep->declBit(c+13,"io_sda", false,-1);
        tracep->declBit(c+14,"io_scl", false,-1);
        tracep->declBit(c+9,"I2C_Top clock", false,-1);
        tracep->declBit(c+10,"I2C_Top reset", false,-1);
        tracep->declBus(c+11,"I2C_Top io_wdata", false,-1, 31,0);
        tracep->declBus(c+12,"I2C_Top io_addr", false,-1, 6,0);
        tracep->declBit(c+13,"I2C_Top io_sda", false,-1);
        tracep->declBit(c+14,"I2C_Top io_scl", false,-1);
        tracep->declBit(c+9,"I2C_Top i2c_clock", false,-1);
        tracep->declBit(c+10,"I2C_Top i2c_reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c_io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c_io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c_io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c_io_read_write", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c_io_data_ack", false,-1);
        tracep->declBit(c+15,"I2C_Top i2c_io_i2c_sda", false,-1);
        tracep->declBit(c+16,"I2C_Top i2c_io_i2c_scl", false,-1);
        tracep->declBit(c+1,"I2C_Top addr_start_bit", false,-1);
        tracep->declBus(c+2,"I2C_Top addr_slave_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top addr_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top addr_read_write_bit", false,-1);
        tracep->declBit(c+5,"I2C_Top addr_data_ack", false,-1);
        tracep->declBit(c+9,"I2C_Top i2c clock", false,-1);
        tracep->declBit(c+10,"I2C_Top i2c reset", false,-1);
        tracep->declBit(c+1,"I2C_Top i2c io_start", false,-1);
        tracep->declBus(c+2,"I2C_Top i2c io_addr", false,-1, 6,0);
        tracep->declBus(c+3,"I2C_Top i2c io_data", false,-1, 7,0);
        tracep->declBit(c+4,"I2C_Top i2c io_read_write", false,-1);
        tracep->declBit(c+5,"I2C_Top i2c io_data_ack", false,-1);
        tracep->declBit(c+15,"I2C_Top i2c io_i2c_sda", false,-1);
        tracep->declBit(c+16,"I2C_Top i2c io_i2c_scl", false,-1);
        tracep->declBus(c+6,"I2C_Top i2c state", false,-1, 7,0);
        tracep->declBus(c+7,"I2C_Top i2c count", false,-1, 14,0);
        tracep->declBit(c+8,"I2C_Top i2c i2c_scl_enable", false,-1);
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
        tracep->fullBit(oldp+5,(vlTOPp->I2C_Top__DOT__addr_data_ack));
        tracep->fullCData(oldp+6,(vlTOPp->I2C_Top__DOT__i2c__DOT__state),8);
        tracep->fullSData(oldp+7,(vlTOPp->I2C_Top__DOT__i2c__DOT__count),15);
        tracep->fullBit(oldp+8,(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable));
        tracep->fullBit(oldp+9,(vlTOPp->clock));
        tracep->fullBit(oldp+10,(vlTOPp->reset));
        tracep->fullIData(oldp+11,(vlTOPp->io_wdata),32);
        tracep->fullCData(oldp+12,(vlTOPp->io_addr),7);
        tracep->fullBit(oldp+13,(vlTOPp->io_sda));
        tracep->fullBit(oldp+14,(vlTOPp->io_scl));
        tracep->fullBit(oldp+15,(((IData)(vlTOPp->reset) 
                                  | ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                     | ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                        & ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                            ? ((6U 
                                                >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                ? (0x7fU 
                                                   & ((IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr) 
                                                      >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                                : 0U)
                                            : ((3U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                                : (
                                                   (4U 
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
                                                    | (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack))))))))));
        tracep->fullBit(oldp+16,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable)) 
                                        | (~ (IData)(vlTOPp->clock))))));
    }
}
