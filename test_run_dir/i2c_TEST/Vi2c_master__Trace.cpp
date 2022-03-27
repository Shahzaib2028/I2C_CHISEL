// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_master__Syms.h"


void Vi2c_master::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vi2c_master::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->i2c_master__DOT__state),8);
            tracep->chgSData(oldp+1,(vlTOPp->i2c_master__DOT__count),15);
            tracep->chgCData(oldp+2,(vlTOPp->i2c_master__DOT__saved_addr),7);
            tracep->chgCData(oldp+3,(vlTOPp->i2c_master__DOT__saved_data),8);
            tracep->chgBit(oldp+4,(vlTOPp->i2c_master__DOT__i2c_scl_enable));
        }
        tracep->chgBit(oldp+5,(vlTOPp->clock));
        tracep->chgBit(oldp+6,(vlTOPp->reset));
        tracep->chgBit(oldp+7,(vlTOPp->io_start));
        tracep->chgCData(oldp+8,(vlTOPp->io_addr),7);
        tracep->chgCData(oldp+9,(vlTOPp->io_data),8);
        tracep->chgBit(oldp+10,(vlTOPp->io_read_write));
        tracep->chgBit(oldp+11,(vlTOPp->io_ack));
        tracep->chgBit(oldp+12,(vlTOPp->io_data_ack));
        tracep->chgBit(oldp+13,(vlTOPp->io_i2c_sda));
        tracep->chgBit(oldp+14,(vlTOPp->io_i2c_scl));
        tracep->chgBit(oldp+15,(vlTOPp->io_ready));
        tracep->chgBit(oldp+16,(vlTOPp->io_stop));
    }
}

void Vi2c_master::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vi2c_master__Syms* __restrict vlSymsp = static_cast<Vi2c_master__Syms*>(userp);
    Vi2c_master* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
