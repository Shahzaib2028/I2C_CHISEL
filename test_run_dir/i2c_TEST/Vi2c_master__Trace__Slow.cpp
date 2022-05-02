// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_master__Syms.h"


//======================

void Vi2c_master::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vi2c_master::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vi2c_master::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vi2c_master::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vi2c_master::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+6,"clock", false,-1);
        tracep->declBit(c+7,"reset", false,-1);
        tracep->declBit(c+8,"io_start", false,-1);
        tracep->declBus(c+9,"io_addr", false,-1, 6,0);
        tracep->declBus(c+10,"io_data", false,-1, 7,0);
        tracep->declBit(c+11,"io_read_write", false,-1);
        tracep->declBit(c+12,"io_i2c_sda_in", false,-1);
        tracep->declBit(c+13,"io_i2c_sda", false,-1);
        tracep->declBit(c+14,"io_i2c_scl", false,-1);
        tracep->declBit(c+15,"io_ready", false,-1);
        tracep->declBit(c+16,"io_stop", false,-1);
        tracep->declBit(c+17,"io_i2c_intr", false,-1);
        tracep->declBit(c+6,"i2c_master clock", false,-1);
        tracep->declBit(c+7,"i2c_master reset", false,-1);
        tracep->declBit(c+8,"i2c_master io_start", false,-1);
        tracep->declBus(c+9,"i2c_master io_addr", false,-1, 6,0);
        tracep->declBus(c+10,"i2c_master io_data", false,-1, 7,0);
        tracep->declBit(c+11,"i2c_master io_read_write", false,-1);
        tracep->declBit(c+12,"i2c_master io_i2c_sda_in", false,-1);
        tracep->declBit(c+13,"i2c_master io_i2c_sda", false,-1);
        tracep->declBit(c+14,"i2c_master io_i2c_scl", false,-1);
        tracep->declBit(c+15,"i2c_master io_ready", false,-1);
        tracep->declBit(c+16,"i2c_master io_stop", false,-1);
        tracep->declBit(c+17,"i2c_master io_i2c_intr", false,-1);
        tracep->declBus(c+1,"i2c_master state", false,-1, 7,0);
        tracep->declBus(c+2,"i2c_master count", false,-1, 14,0);
        tracep->declBus(c+3,"i2c_master saved_addr", false,-1, 6,0);
        tracep->declBit(c+4,"i2c_master i2c_scl_enable", false,-1);
        tracep->declBit(c+5,"i2c_master intr_done", false,-1);
    }
}

void Vi2c_master::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vi2c_master::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vi2c_master::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->i2c_master__DOT__state),8);
        tracep->fullSData(oldp+2,(vlTOPp->i2c_master__DOT__count),15);
        tracep->fullCData(oldp+3,(vlTOPp->i2c_master__DOT__saved_addr),7);
        tracep->fullBit(oldp+4,(vlTOPp->i2c_master__DOT__i2c_scl_enable));
        tracep->fullBit(oldp+5,(vlTOPp->i2c_master__DOT__intr_done));
        tracep->fullBit(oldp+6,(vlTOPp->clock));
        tracep->fullBit(oldp+7,(vlTOPp->reset));
        tracep->fullBit(oldp+8,(vlTOPp->io_start));
        tracep->fullCData(oldp+9,(vlTOPp->io_addr),7);
        tracep->fullCData(oldp+10,(vlTOPp->io_data),8);
        tracep->fullBit(oldp+11,(vlTOPp->io_read_write));
        tracep->fullBit(oldp+12,(vlTOPp->io_i2c_sda_in));
        tracep->fullBit(oldp+13,(vlTOPp->io_i2c_sda));
        tracep->fullBit(oldp+14,(vlTOPp->io_i2c_scl));
        tracep->fullBit(oldp+15,(vlTOPp->io_ready));
        tracep->fullBit(oldp+16,(vlTOPp->io_stop));
        tracep->fullBit(oldp+17,(vlTOPp->io_i2c_intr));
    }
}
