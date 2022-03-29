// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_master__Syms.h"


//======================

void Vi2c_master::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vi2c_master* t = (Vi2c_master*)userthis;
    Vi2c_master__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vi2c_master::traceChgThis(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vi2c_master::traceChgThis__2(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->i2c_master__DOT__state),8);
        vcdp->chgBus(c+9,(vlTOPp->i2c_master__DOT__count),15);
        vcdp->chgBit(c+17,(vlTOPp->i2c_master__DOT__i2c_scl_enable));
        vcdp->chgBit(c+25,(vlTOPp->i2c_master__DOT__intr_done));
    }
}

void Vi2c_master::traceChgThis__3(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+33,(vlTOPp->clock));
        vcdp->chgBit(c+41,(vlTOPp->reset));
        vcdp->chgBit(c+49,(vlTOPp->io_start));
        vcdp->chgBus(c+57,(vlTOPp->io_addr),7);
        vcdp->chgBus(c+65,(vlTOPp->io_data),8);
        vcdp->chgBit(c+73,(vlTOPp->io_read_write));
        vcdp->chgBit(c+81,(vlTOPp->io_i2c_sda_in));
        vcdp->chgBit(c+89,(vlTOPp->io_i2c_sda));
        vcdp->chgBit(c+97,(vlTOPp->io_i2c_scl));
        vcdp->chgBit(c+105,(vlTOPp->io_ready));
        vcdp->chgBit(c+113,(vlTOPp->io_stop));
        vcdp->chgBit(c+121,(vlTOPp->io_i2c_intr));
    }
}
