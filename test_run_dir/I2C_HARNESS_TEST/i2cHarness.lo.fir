circuit i2cHarness :
  module WishboneHost :
    input clock : Clock
    input reset : UInt<1>
    input io_wbMasterTransmitter_ready : UInt<1>
    output io_wbMasterTransmitter_valid : UInt<1>
    output io_wbMasterTransmitter_bits_cyc : UInt<1>
    output io_wbMasterTransmitter_bits_stb : UInt<1>
    output io_wbMasterTransmitter_bits_we : UInt<1>
    output io_wbMasterTransmitter_bits_adr : UInt<32>
    output io_wbMasterTransmitter_bits_dat : UInt<32>
    output io_wbMasterTransmitter_bits_sel : UInt<4>
    output io_wbSlaveReceiver_ready : UInt<1>
    input io_wbSlaveReceiver_valid : UInt<1>
    input io_wbSlaveReceiver_bits_ack : UInt<1>
    input io_wbSlaveReceiver_bits_dat : UInt<32>
    input io_wbSlaveReceiver_bits_err : UInt<1>
    output io_reqIn_ready : UInt<1>
    input io_reqIn_valid : UInt<1>
    input io_reqIn_bits_addrRequest : UInt<32>
    input io_reqIn_bits_dataRequest : UInt<32>
    input io_reqIn_bits_activeByteLane : UInt<4>
    input io_reqIn_bits_isWrite : UInt<1>
    input io_rspOut_ready : UInt<1>
    output io_rspOut_valid : UInt<1>
    output io_rspOut_bits_dataResponse : UInt<32>
    output io_rspOut_bits_error : UInt<1>

    node _T = asUInt(reset) @[WishboneHost.scala 30:20]
    node _T_1 = eq(_T, UInt<1>("h1")) @[WishboneHost.scala 30:23]
    reg startWBTransaction : UInt<1>, clock with :
      reset => (UInt<1>("h0"), startWBTransaction) @[WishboneHost.scala 39:35]
    reg dataReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), dataReg) @[WishboneHost.scala 41:24]
    reg respReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), respReg) @[WishboneHost.scala 42:24]
    reg errReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), errReg) @[WishboneHost.scala 43:23]
    reg stbReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stbReg) @[WishboneHost.scala 45:23]
    reg cycReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), cycReg) @[WishboneHost.scala 46:23]
    reg weReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), weReg) @[WishboneHost.scala 47:22]
    reg datReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), datReg) @[WishboneHost.scala 48:23]
    reg adrReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), adrReg) @[WishboneHost.scala 49:23]
    reg selReg : UInt<4>, clock with :
      reset => (UInt<1>("h0"), selReg) @[WishboneHost.scala 50:23]
    reg stateReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stateReg) @[WishboneHost.scala 55:25]
    reg readyReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), readyReg) @[WishboneHost.scala 61:25]
    node _T_2 = and(io_reqIn_valid, io_wbMasterTransmitter_ready) @[WishboneHost.scala 18:37]
    node _GEN_0 = mux(_T_2, UInt<1>("h0"), readyReg) @[WishboneHost.scala 62:14 WishboneHost.scala 63:14 WishboneHost.scala 61:25]
    node _T_3 = eq(stateReg, UInt<1>("h1")) @[WishboneHost.scala 65:17]
    node _GEN_1 = mux(_T_3, UInt<1>("h1"), _GEN_0) @[WishboneHost.scala 65:33 WishboneHost.scala 66:14]
    node _T_4 = eq(io_reqIn_bits_isWrite, UInt<1>("h0")) @[WishboneHost.scala 76:32]
    node _T_5 = eq(readyReg, UInt<1>("h1")) @[WishboneHost.scala 76:56]
    node _T_6 = and(_T_4, _T_5) @[WishboneHost.scala 76:44]
    node _T_7 = and(_T_6, io_reqIn_valid) @[WishboneHost.scala 76:67]
    node _T_8 = eq(io_reqIn_bits_isWrite, UInt<1>("h1")) @[WishboneHost.scala 84:39]
    node _T_9 = eq(readyReg, UInt<1>("h1")) @[WishboneHost.scala 84:62]
    node _T_10 = and(_T_8, _T_9) @[WishboneHost.scala 84:50]
    node _T_11 = and(_T_10, io_reqIn_valid) @[WishboneHost.scala 84:73]
    node _GEN_2 = mux(_T_11, UInt<1>("h1"), startWBTransaction) @[WishboneHost.scala 84:92 WishboneHost.scala 85:26 WishboneHost.scala 39:35]
    node _GEN_3 = mux(_T_11, UInt<1>("h1"), stbReg) @[WishboneHost.scala 84:92 WishboneHost.scala 86:14 WishboneHost.scala 45:23]
    node _GEN_4 = mux(_T_11, UInt<1>("h1"), cycReg) @[WishboneHost.scala 84:92 WishboneHost.scala 87:14 WishboneHost.scala 46:23]
    node _GEN_5 = mux(_T_11, io_reqIn_bits_isWrite, weReg) @[WishboneHost.scala 84:92 WishboneHost.scala 88:13 WishboneHost.scala 47:22]
    node _GEN_6 = mux(_T_11, io_reqIn_bits_addrRequest, adrReg) @[WishboneHost.scala 84:92 WishboneHost.scala 89:14 WishboneHost.scala 49:23]
    node _GEN_7 = mux(_T_11, io_reqIn_bits_dataRequest, datReg) @[WishboneHost.scala 84:92 WishboneHost.scala 90:14 WishboneHost.scala 48:23]
    node _GEN_8 = mux(_T_11, io_reqIn_bits_activeByteLane, selReg) @[WishboneHost.scala 84:92 WishboneHost.scala 91:14 WishboneHost.scala 50:23]
    node _GEN_9 = mux(_T_7, UInt<1>("h1"), _GEN_2) @[WishboneHost.scala 76:86 WishboneHost.scala 77:26]
    node _GEN_10 = mux(_T_7, UInt<1>("h1"), _GEN_3) @[WishboneHost.scala 76:86 WishboneHost.scala 78:14]
    node _GEN_11 = mux(_T_7, UInt<1>("h1"), _GEN_4) @[WishboneHost.scala 76:86 WishboneHost.scala 79:14]
    node _GEN_12 = mux(_T_7, io_reqIn_bits_isWrite, _GEN_5) @[WishboneHost.scala 76:86 WishboneHost.scala 80:13]
    node _GEN_13 = mux(_T_7, io_reqIn_bits_addrRequest, _GEN_6) @[WishboneHost.scala 76:86 WishboneHost.scala 81:14]
    node _GEN_14 = mux(_T_7, UInt<1>("h0"), _GEN_7) @[WishboneHost.scala 76:86 WishboneHost.scala 82:14]
    node _GEN_15 = mux(_T_7, io_reqIn_bits_activeByteLane, _GEN_8) @[WishboneHost.scala 76:86 WishboneHost.scala 83:14]
    node _T_12 = eq(startWBTransaction, UInt<1>("h0")) @[WishboneHost.scala 101:10]
    node _GEN_16 = mux(_T_12, UInt<1>("h0"), selReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 99:37]
    node _GEN_17 = mux(_T_12, UInt<1>("h0"), datReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 98:37]
    node _GEN_18 = mux(_T_12, UInt<1>("h0"), adrReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 97:37]
    node _GEN_19 = mux(_T_12, UInt<1>("h0"), weReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 96:36]
    node _GEN_20 = mux(_T_12, UInt<1>("h0"), stbReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 94:37]
    node _GEN_21 = mux(_T_12, UInt<1>("h0"), cycReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 95:37]
    node _T_13 = eq(io_wbSlaveReceiver_bits_err, UInt<1>("h0")) @[WishboneHost.scala 105:41]
    node _T_14 = and(io_wbSlaveReceiver_bits_ack, _T_13) @[WishboneHost.scala 105:38]
    node _T_15 = eq(io_wbSlaveReceiver_bits_ack, UInt<1>("h0")) @[WishboneHost.scala 111:48]
    node _T_16 = and(io_wbSlaveReceiver_bits_err, _T_15) @[WishboneHost.scala 111:45]
    node _GEN_22 = mux(_T_16, io_wbSlaveReceiver_bits_dat, dataReg) @[WishboneHost.scala 111:78 WishboneHost.scala 112:15 WishboneHost.scala 41:24]
    node _GEN_23 = mux(_T_16, UInt<1>("h1"), respReg) @[WishboneHost.scala 111:78 WishboneHost.scala 113:15 WishboneHost.scala 42:24]
    node _GEN_24 = mux(_T_16, UInt<1>("h1"), errReg) @[WishboneHost.scala 111:78 WishboneHost.scala 114:14 WishboneHost.scala 43:23]
    node _GEN_25 = mux(_T_16, UInt<1>("h0"), _GEN_9) @[WishboneHost.scala 111:78 WishboneHost.scala 115:26]
    node _GEN_26 = mux(_T_14, io_wbSlaveReceiver_bits_dat, _GEN_22) @[WishboneHost.scala 105:71 WishboneHost.scala 106:15]
    node _GEN_27 = mux(_T_14, UInt<1>("h1"), _GEN_23) @[WishboneHost.scala 105:71 WishboneHost.scala 107:15]
    node _GEN_28 = mux(_T_14, UInt<1>("h0"), _GEN_24) @[WishboneHost.scala 105:71 WishboneHost.scala 108:14]
    node _GEN_29 = mux(_T_14, UInt<1>("h0"), _GEN_25) @[WishboneHost.scala 105:71 WishboneHost.scala 110:26]
    node _T_17 = eq(stateReg, UInt<1>("h0")) @[WishboneHost.scala 118:19]
    node _stateReg_T = or(io_wbSlaveReceiver_bits_ack, io_wbSlaveReceiver_bits_err) @[WishboneHost.scala 119:51]
    node _stateReg_T_1 = mux(_stateReg_T, UInt<1>("h1"), UInt<1>("h0")) @[WishboneHost.scala 119:22]
    node _T_18 = eq(stateReg, UInt<1>("h1")) @[WishboneHost.scala 120:26]
    node _GEN_30 = mux(_T_18, UInt<1>("h0"), _GEN_27) @[WishboneHost.scala 120:42 WishboneHost.scala 121:15]
    node _GEN_31 = mux(_T_18, UInt<1>("h0"), stateReg) @[WishboneHost.scala 120:42 WishboneHost.scala 122:16 WishboneHost.scala 55:25]
    node _GEN_32 = mux(_T_17, _stateReg_T_1, _GEN_31) @[WishboneHost.scala 118:29 WishboneHost.scala 119:16]
    node _GEN_33 = mux(_T_17, _GEN_27, _GEN_30) @[WishboneHost.scala 118:29]
    io_wbMasterTransmitter_valid <= io_wbMasterTransmitter_bits_stb @[WishboneHost.scala 23:32]
    io_wbMasterTransmitter_bits_cyc <= _GEN_21
    io_wbMasterTransmitter_bits_stb <= _GEN_20
    io_wbMasterTransmitter_bits_we <= _GEN_19
    io_wbMasterTransmitter_bits_adr <= _GEN_18
    io_wbMasterTransmitter_bits_dat <= _GEN_17
    io_wbMasterTransmitter_bits_sel <= _GEN_16
    io_wbSlaveReceiver_ready <= UInt<1>("h1") @[WishboneHost.scala 26:28]
    io_reqIn_ready <= readyReg @[WishboneHost.scala 75:20]
    io_rspOut_valid <= respReg @[WishboneHost.scala 127:21]
    io_rspOut_bits_dataResponse <= dataReg @[WishboneHost.scala 128:33]
    io_rspOut_bits_error <= errReg @[WishboneHost.scala 129:26]
    startWBTransaction <= mux(reset, UInt<1>("h0"), _GEN_29) @[WishboneHost.scala 39:35 WishboneHost.scala 39:35]
    dataReg <= mux(reset, UInt<32>("h0"), _GEN_26) @[WishboneHost.scala 41:24 WishboneHost.scala 41:24]
    respReg <= mux(reset, UInt<1>("h0"), _GEN_33) @[WishboneHost.scala 42:24 WishboneHost.scala 42:24]
    errReg <= mux(reset, UInt<1>("h0"), _GEN_28) @[WishboneHost.scala 43:23 WishboneHost.scala 43:23]
    stbReg <= mux(reset, UInt<1>("h0"), _GEN_10) @[WishboneHost.scala 45:23 WishboneHost.scala 45:23]
    cycReg <= mux(reset, UInt<1>("h0"), _GEN_11) @[WishboneHost.scala 46:23 WishboneHost.scala 46:23]
    weReg <= mux(reset, UInt<1>("h0"), _GEN_12) @[WishboneHost.scala 47:22 WishboneHost.scala 47:22]
    datReg <= mux(reset, UInt<1>("h0"), _GEN_14) @[WishboneHost.scala 48:23 WishboneHost.scala 48:23]
    adrReg <= mux(reset, UInt<1>("h0"), _GEN_13) @[WishboneHost.scala 49:23 WishboneHost.scala 49:23]
    selReg <= mux(reset, UInt<1>("h0"), _GEN_15) @[WishboneHost.scala 50:23 WishboneHost.scala 50:23]
    stateReg <= mux(reset, UInt<1>("h0"), _GEN_32) @[WishboneHost.scala 55:25 WishboneHost.scala 55:25]
    readyReg <= mux(reset, UInt<1>("h1"), _GEN_1) @[WishboneHost.scala 61:25 WishboneHost.scala 61:25]

  module WishboneDevice :
    input clock : Clock
    input reset : UInt<1>
    input io_wbSlaveTransmitter_ready : UInt<1>
    output io_wbSlaveTransmitter_valid : UInt<1>
    output io_wbSlaveTransmitter_bits_ack : UInt<1>
    output io_wbSlaveTransmitter_bits_dat : UInt<32>
    output io_wbSlaveTransmitter_bits_err : UInt<1>
    output io_wbMasterReceiver_ready : UInt<1>
    input io_wbMasterReceiver_valid : UInt<1>
    input io_wbMasterReceiver_bits_cyc : UInt<1>
    input io_wbMasterReceiver_bits_stb : UInt<1>
    input io_wbMasterReceiver_bits_we : UInt<1>
    input io_wbMasterReceiver_bits_adr : UInt<32>
    input io_wbMasterReceiver_bits_dat : UInt<32>
    input io_wbMasterReceiver_bits_sel : UInt<4>
    input io_reqOut_ready : UInt<1>
    output io_reqOut_valid : UInt<1>
    output io_reqOut_bits_addrRequest : UInt<32>
    output io_reqOut_bits_dataRequest : UInt<32>
    output io_reqOut_bits_activeByteLane : UInt<4>
    output io_reqOut_bits_isWrite : UInt<1>
    output io_rspIn_ready : UInt<1>
    input io_rspIn_valid : UInt<1>
    input io_rspIn_bits_dataResponse : UInt<32>
    input io_rspIn_bits_error : UInt<1>

    node _T = and(io_wbMasterReceiver_valid, io_wbMasterReceiver_bits_cyc) @[WishboneDevice.scala 16:48]
    node _T_1 = and(_T, io_wbMasterReceiver_bits_stb) @[WishboneDevice.scala 16:80]
    node _T_2 = eq(io_wbMasterReceiver_bits_we, UInt<1>("h0")) @[WishboneDevice.scala 26:10]
    node _T_3 = eq(io_rspIn_bits_error, UInt<1>("h0")) @[WishboneDevice.scala 36:30]
    node _T_4 = and(io_rspIn_valid, _T_3) @[WishboneDevice.scala 36:27]
    node _T_5 = and(io_rspIn_valid, io_rspIn_bits_error) @[WishboneDevice.scala 42:34]
    node _GEN_0 = mux(_T_5, UInt<1>("h1"), UInt<1>("h0")) @[WishboneDevice.scala 42:58 WishboneDevice.scala 43:37 WishboneDevice.scala 48:37]
    node _GEN_1 = mux(_T_5, UInt<1>("h0"), UInt<1>("h0")) @[WishboneDevice.scala 42:58 WishboneDevice.scala 44:13 WishboneDevice.scala 49:13]
    node _GEN_2 = validif(_T_5, io_rspIn_bits_dataResponse) @[WishboneDevice.scala 42:58 WishboneDevice.scala 46:40]
    node _GEN_3 = mux(_T_4, UInt<1>("h1"), _GEN_0) @[WishboneDevice.scala 36:52 WishboneDevice.scala 38:37]
    node _GEN_4 = mux(_T_4, UInt<1>("h1"), _GEN_1) @[WishboneDevice.scala 36:52 WishboneDevice.scala 39:13]
    node _GEN_5 = mux(_T_4, UInt<1>("h0"), _GEN_0) @[WishboneDevice.scala 36:52 WishboneDevice.scala 40:40]
    node _GEN_6 = mux(_T_4, io_rspIn_bits_dataResponse, _GEN_2) @[WishboneDevice.scala 36:52 WishboneDevice.scala 41:40]
    node _T_6 = eq(io_rspIn_bits_error, UInt<1>("h0")) @[WishboneDevice.scala 60:30]
    node _T_7 = and(io_rspIn_valid, _T_6) @[WishboneDevice.scala 60:27]
    node _T_8 = and(io_rspIn_valid, io_rspIn_bits_error) @[WishboneDevice.scala 65:34]
    node _GEN_7 = mux(_T_8, UInt<1>("h1"), UInt<1>("h0")) @[WishboneDevice.scala 65:58 WishboneDevice.scala 66:37 WishboneDevice.scala 71:37]
    node _GEN_8 = mux(_T_8, UInt<1>("h0"), UInt<1>("h0")) @[WishboneDevice.scala 65:58 WishboneDevice.scala 67:13 WishboneDevice.scala 72:13]
    node _GEN_9 = mux(_T_7, UInt<1>("h1"), _GEN_7) @[WishboneDevice.scala 60:52 WishboneDevice.scala 61:37]
    node _GEN_10 = mux(_T_7, UInt<1>("h1"), _GEN_8) @[WishboneDevice.scala 60:52 WishboneDevice.scala 62:13]
    node _GEN_11 = mux(_T_7, UInt<1>("h0"), _GEN_7) @[WishboneDevice.scala 60:52 WishboneDevice.scala 63:40]
    node _GEN_12 = mux(_T_2, UInt<1>("h1"), UInt<1>("h1")) @[WishboneDevice.scala 26:40 WishboneDevice.scala 31:23 WishboneDevice.scala 55:23]
    node _GEN_13 = mux(_T_2, io_wbMasterReceiver_bits_adr, io_wbMasterReceiver_bits_adr) @[WishboneDevice.scala 26:40 WishboneDevice.scala 32:34 WishboneDevice.scala 56:34]
    node _GEN_14 = validif(eq(_T_2, UInt<1>("h0")), io_wbMasterReceiver_bits_dat) @[WishboneDevice.scala 26:40 WishboneDevice.scala 57:34]
    node _GEN_15 = mux(_T_2, io_wbMasterReceiver_bits_sel, io_wbMasterReceiver_bits_sel) @[WishboneDevice.scala 26:40 WishboneDevice.scala 34:37 WishboneDevice.scala 58:37]
    node _GEN_16 = mux(_T_2, UInt<1>("h0"), io_wbMasterReceiver_bits_we) @[WishboneDevice.scala 26:40 WishboneDevice.scala 35:30 WishboneDevice.scala 59:30]
    node _GEN_17 = mux(_T_2, _GEN_3, _GEN_9) @[WishboneDevice.scala 26:40]
    node _GEN_18 = mux(_T_2, _GEN_4, _GEN_10) @[WishboneDevice.scala 26:40]
    node _GEN_19 = mux(_T_2, _GEN_5, _GEN_11) @[WishboneDevice.scala 26:40]
    node _GEN_20 = validif(_T_2, _GEN_6) @[WishboneDevice.scala 26:40]
    node _GEN_21 = mux(_T_1, _GEN_12, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 81:21]
    node _GEN_22 = validif(_T_1, _GEN_13) @[WishboneDevice.scala 25:16]
    node _GEN_23 = validif(_T_1, _GEN_14) @[WishboneDevice.scala 25:16]
    node _GEN_24 = validif(_T_1, _GEN_15) @[WishboneDevice.scala 25:16]
    node _GEN_25 = validif(_T_1, _GEN_16) @[WishboneDevice.scala 25:16]
    node _GEN_26 = mux(_T_1, _GEN_17, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 87:33]
    node _GEN_27 = mux(_T_1, _GEN_18, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 88:9]
    node _GEN_28 = mux(_T_1, _GEN_19, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 89:36]
    node _GEN_29 = validif(_T_1, _GEN_20) @[WishboneDevice.scala 25:16]
    node ack = _GEN_27
    io_wbSlaveTransmitter_valid <= _GEN_26
    io_wbSlaveTransmitter_bits_ack <= ack @[WishboneDevice.scala 93:34]
    io_wbSlaveTransmitter_bits_dat <= _GEN_29
    io_wbSlaveTransmitter_bits_err <= _GEN_28
    io_wbMasterReceiver_ready <= UInt<1>("h1") @[WishboneDevice.scala 19:29]
    io_reqOut_valid <= _GEN_21
    io_reqOut_bits_addrRequest <= _GEN_22
    io_reqOut_bits_dataRequest <= _GEN_23
    io_reqOut_bits_activeByteLane <= _GEN_24
    io_reqOut_bits_isWrite <= _GEN_25
    io_rspIn_ready <= UInt<1>("h1") @[WishboneDevice.scala 23:18]

  module i2c_master :
    input clock : Clock
    input reset : UInt<1>
    input io_start : UInt<1>
    input io_addr : UInt<7>
    input io_data : UInt<8>
    input io_read_write : UInt<1>
    input io_i2c_sda_in : UInt<1>
    output io_i2c_sda : UInt<1>
    output io_i2c_scl : UInt<1>
    output io_ready : UInt<1>
    output io_stop : UInt<1>
    output io_i2c_intr : UInt<1>

    reg state : UInt<8>, clock with :
      reset => (UInt<1>("h0"), state) @[i2c_master.scala 25:24]
    reg count : UInt<15>, clock with :
      reset => (UInt<1>("h0"), count) @[i2c_master.scala 26:24]
    reg saved_addr : UInt<7>, clock with :
      reset => (UInt<1>("h0"), saved_addr) @[i2c_master.scala 27:29]
    reg saved_data : UInt<8>, clock with :
      reset => (UInt<1>("h0"), saved_data) @[i2c_master.scala 28:29]
    reg i2c_scl_enable : UInt<1>, clock with :
      reset => (UInt<1>("h0"), i2c_scl_enable) @[i2c_master.scala 29:33]
    reg intr_done : UInt<1>, clock with :
      reset => (UInt<1>("h0"), intr_done) @[i2c_master.scala 30:28]
    reg WACK11 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), WACK11) @[i2c_master.scala 35:25]
    reg WACK22 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), WACK22) @[i2c_master.scala 36:25]
    node _clk_T = asUInt(clock) @[i2c_master.scala 46:36]
    node _clk_T_1 = bits(_clk_T, 0, 0) @[i2c_master.scala 46:38]
    node _rst_T = asUInt(reset) @[i2c_master.scala 47:36]
    node _rst_T_1 = bits(_rst_T, 0, 0) @[i2c_master.scala 47:38]
    node _io_i2c_scl_T = eq(i2c_scl_enable, UInt<1>("h0")) @[i2c_master.scala 49:38]
    node clk = _clk_T_1
    node _io_i2c_scl_T_1 = not(clk) @[i2c_master.scala 49:54]
    node _io_i2c_scl_T_2 = mux(_io_i2c_scl_T, UInt<1>("h1"), _io_i2c_scl_T_1) @[i2c_master.scala 49:22]
    node rst = _rst_T_1
    node _T = eq(rst, UInt<1>("h1")) @[i2c_master.scala 51:14]
    node _T_1 = eq(state, UInt<3>("h0")) @[i2c_master.scala 54:22]
    node _T_2 = eq(state, UInt<3>("h1")) @[i2c_master.scala 54:46]
    node _T_3 = or(_T_1, _T_2) @[i2c_master.scala 54:37]
    node _T_4 = eq(state, UInt<3>("h7")) @[i2c_master.scala 54:71]
    node _T_5 = or(_T_3, _T_4) @[i2c_master.scala 54:62]
    node _GEN_0 = mux(_T_5, UInt<1>("h0"), UInt<1>("h1")) @[i2c_master.scala 54:87 i2c_master.scala 55:28 i2c_master.scala 57:29]
    node _GEN_1 = mux(_T, UInt<1>("h0"), _GEN_0) @[i2c_master.scala 51:22 i2c_master.scala 52:24]
    node _T_6 = eq(rst, UInt<1>("h1")) @[i2c_master.scala 61:14]
    node _T_7 = eq(UInt<3>("h0"), state) @[Conditional.scala 37:30]
    node _T_8 = eq(io_start, UInt<1>("h1")) @[i2c_master.scala 69:31]
    node _GEN_2 = mux(_T_8, UInt<3>("h1"), UInt<3>("h0")) @[i2c_master.scala 69:39 i2c_master.scala 70:27 i2c_master.scala 74:27]
    node _GEN_3 = mux(_T_8, UInt<1>("h0"), UInt<1>("h0")) @[i2c_master.scala 69:39 i2c_master.scala 71:30 i2c_master.scala 43:14]
    node _T_9 = eq(UInt<3>("h1"), state) @[Conditional.scala 37:30]
    node _T_10 = eq(UInt<3>("h2"), state) @[Conditional.scala 37:30]
    node _io_i2c_sda_T = dshr(io_addr, count) @[i2c_master.scala 90:38]
    node _io_i2c_sda_T_1 = bits(_io_i2c_sda_T, 0, 0) @[i2c_master.scala 90:38]
    node _T_11 = eq(count, UInt<1>("h0")) @[i2c_master.scala 93:28]
    node _count_T = sub(count, UInt<1>("h1")) @[i2c_master.scala 96:36]
    node _count_T_1 = tail(_count_T, 1) @[i2c_master.scala 96:36]
    node _GEN_4 = mux(_T_11, UInt<3>("h3"), UInt<3>("h2")) @[i2c_master.scala 93:36 i2c_master.scala 94:27 i2c_master.scala 97:27]
    node _GEN_5 = mux(_T_11, count, _count_T_1) @[i2c_master.scala 93:36 i2c_master.scala 26:24 i2c_master.scala 96:27]
    node _T_12 = eq(UInt<3>("h3"), state) @[Conditional.scala 37:30]
    node _T_13 = eq(io_read_write, UInt<1>("h0")) @[i2c_master.scala 103:36]
    node _GEN_6 = mux(_T_13, UInt<1>("h0"), UInt<1>("h1")) @[i2c_master.scala 103:44 i2c_master.scala 104:32 i2c_master.scala 110:32]
    node _GEN_7 = mux(_T_13, UInt<1>("h0"), UInt<1>("h0")) @[i2c_master.scala 103:44 i2c_master.scala 105:30 i2c_master.scala 111:30]
    node _GEN_8 = mux(_T_13, UInt<3>("h4"), UInt<3>("h4")) @[i2c_master.scala 103:44 i2c_master.scala 107:27 i2c_master.scala 113:27]
    node _GEN_9 = mux(_T_13, UInt<4>("h8"), UInt<3>("h7")) @[i2c_master.scala 103:44 i2c_master.scala 108:27 i2c_master.scala 114:27]
    node _T_14 = eq(UInt<3>("h4"), state) @[Conditional.scala 37:30]
    node _T_15 = eq(io_i2c_sda_in, UInt<1>("h0")) @[i2c_master.scala 120:36]
    node _GEN_10 = mux(_T_15, io_i2c_sda_in, io_i2c_sda_in) @[i2c_master.scala 120:44 i2c_master.scala 121:28 i2c_master.scala 126:32]
    node _GEN_11 = mux(_T_15, UInt<1>("h0"), UInt<1>("h0")) @[i2c_master.scala 120:44 i2c_master.scala 122:26 i2c_master.scala 127:30]
    node _GEN_12 = mux(_T_15, UInt<3>("h5"), UInt<3>("h7")) @[i2c_master.scala 120:44 i2c_master.scala 124:23 i2c_master.scala 129:27]
    node _T_16 = eq(UInt<3>("h5"), state) @[Conditional.scala 37:30]
    node _io_i2c_sda_T_2 = dshr(io_data, count) @[i2c_master.scala 136:38]
    node _io_i2c_sda_T_3 = bits(_io_i2c_sda_T_2, 0, 0) @[i2c_master.scala 136:38]
    node _T_17 = eq(count, UInt<1>("h0")) @[i2c_master.scala 139:28]
    node _count_T_2 = sub(count, UInt<1>("h1")) @[i2c_master.scala 142:36]
    node _count_T_3 = tail(_count_T_2, 1) @[i2c_master.scala 142:36]
    node _GEN_13 = mux(_T_17, UInt<3>("h6"), UInt<3>("h5")) @[i2c_master.scala 139:36 i2c_master.scala 140:27 i2c_master.scala 143:27]
    node _GEN_14 = mux(_T_17, count, _count_T_3) @[i2c_master.scala 139:36 i2c_master.scala 26:24 i2c_master.scala 142:27]
    node _T_18 = eq(UInt<3>("h6"), state) @[Conditional.scala 37:30]
    node _T_19 = eq(UInt<3>("h7"), state) @[Conditional.scala 37:30]
    node _GEN_15 = mux(_T_19, UInt<1>("h1"), UInt<1>("h1")) @[Conditional.scala 39:67 i2c_master.scala 156:28 i2c_master.scala 42:16]
    node _GEN_16 = mux(_T_19, UInt<1>("h1"), intr_done) @[Conditional.scala 39:67 i2c_master.scala 157:27 i2c_master.scala 30:28]
    node _GEN_17 = mux(_T_19, UInt<1>("h0"), UInt<1>("h0")) @[Conditional.scala 39:67 i2c_master.scala 158:26 i2c_master.scala 43:14]
    node _GEN_18 = mux(_T_19, UInt<3>("h0"), UInt<3>("h0")) @[Conditional.scala 39:67 i2c_master.scala 160:23 i2c_master.scala 40:11]
    node _GEN_19 = mux(_T_18, io_i2c_sda_in, _GEN_15) @[Conditional.scala 39:67 i2c_master.scala 149:28]
    node _GEN_20 = mux(_T_18, UInt<1>("h0"), _GEN_17) @[Conditional.scala 39:67 i2c_master.scala 150:26]
    node _GEN_21 = mux(_T_18, UInt<3>("h7"), _GEN_18) @[Conditional.scala 39:67 i2c_master.scala 152:23]
    node _GEN_22 = mux(_T_18, intr_done, _GEN_16) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_23 = mux(_T_16, _io_i2c_sda_T_3, _GEN_19) @[Conditional.scala 39:67 i2c_master.scala 136:28]
    node _GEN_24 = mux(_T_16, UInt<1>("h0"), _GEN_20) @[Conditional.scala 39:67 i2c_master.scala 137:26]
    node _GEN_25 = mux(_T_16, _GEN_13, _GEN_21) @[Conditional.scala 39:67]
    node _GEN_26 = mux(_T_16, _GEN_14, count) @[Conditional.scala 39:67 i2c_master.scala 26:24]
    node _GEN_27 = mux(_T_16, intr_done, _GEN_22) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_28 = mux(_T_14, _GEN_10, _GEN_23) @[Conditional.scala 39:67]
    node _GEN_29 = mux(_T_14, _GEN_11, _GEN_24) @[Conditional.scala 39:67]
    node _GEN_30 = mux(_T_14, _GEN_12, _GEN_25) @[Conditional.scala 39:67]
    node _GEN_31 = mux(_T_14, count, _GEN_26) @[Conditional.scala 39:67 i2c_master.scala 26:24]
    node _GEN_32 = mux(_T_14, intr_done, _GEN_27) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_33 = mux(_T_12, _GEN_6, _GEN_28) @[Conditional.scala 39:67]
    node _GEN_34 = mux(_T_12, _GEN_7, _GEN_29) @[Conditional.scala 39:67]
    node _GEN_35 = mux(_T_12, _GEN_8, _GEN_30) @[Conditional.scala 39:67]
    node _GEN_36 = mux(_T_12, _GEN_9, _GEN_31) @[Conditional.scala 39:67]
    node _GEN_37 = mux(_T_12, intr_done, _GEN_32) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_38 = mux(_T_10, _io_i2c_sda_T_1, _GEN_33) @[Conditional.scala 39:67 i2c_master.scala 90:28]
    node _GEN_39 = mux(_T_10, UInt<1>("h0"), _GEN_34) @[Conditional.scala 39:67 i2c_master.scala 91:26]
    node _GEN_40 = mux(_T_10, _GEN_4, _GEN_35) @[Conditional.scala 39:67]
    node _GEN_41 = mux(_T_10, _GEN_5, _GEN_36) @[Conditional.scala 39:67]
    node _GEN_42 = mux(_T_10, intr_done, _GEN_37) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_43 = mux(_T_9, UInt<1>("h0"), _GEN_38) @[Conditional.scala 39:67 i2c_master.scala 80:28]
    node _GEN_44 = mux(_T_9, io_addr, saved_addr) @[Conditional.scala 39:67 i2c_master.scala 81:28 i2c_master.scala 27:29]
    node _GEN_45 = mux(_T_9, io_data, saved_data) @[Conditional.scala 39:67 i2c_master.scala 82:28 i2c_master.scala 28:29]
    node _GEN_46 = mux(_T_9, UInt<1>("h1"), _GEN_39) @[Conditional.scala 39:67 i2c_master.scala 83:26]
    node _GEN_47 = mux(_T_9, UInt<1>("h0"), _GEN_39) @[Conditional.scala 39:67 i2c_master.scala 84:25]
    node _GEN_48 = mux(_T_9, UInt<3>("h2"), _GEN_40) @[Conditional.scala 39:67 i2c_master.scala 85:23]
    node _GEN_49 = mux(_T_9, UInt<3>("h6"), _GEN_41) @[Conditional.scala 39:67 i2c_master.scala 86:23]
    node _GEN_50 = mux(_T_9, intr_done, _GEN_42) @[Conditional.scala 39:67 i2c_master.scala 30:28]
    node _GEN_51 = mux(_T_7, UInt<1>("h1"), _GEN_43) @[Conditional.scala 40:58 i2c_master.scala 67:28]
    node _GEN_52 = mux(_T_7, UInt<1>("h0"), _GEN_50) @[Conditional.scala 40:58 i2c_master.scala 68:27]
    node _GEN_53 = mux(_T_7, _GEN_2, _GEN_48) @[Conditional.scala 40:58]
    node _GEN_54 = mux(_T_7, _GEN_3, _GEN_46) @[Conditional.scala 40:58]
    node _GEN_55 = mux(_T_7, _GEN_3, _GEN_47) @[Conditional.scala 40:58]
    node _GEN_56 = mux(_T_7, saved_addr, _GEN_44) @[Conditional.scala 40:58 i2c_master.scala 27:29]
    node _GEN_57 = mux(_T_7, saved_data, _GEN_45) @[Conditional.scala 40:58 i2c_master.scala 28:29]
    node _GEN_58 = mux(_T_7, count, _GEN_49) @[Conditional.scala 40:58 i2c_master.scala 26:24]
    node _GEN_59 = mux(_T_6, UInt<3>("h0"), _GEN_53) @[i2c_master.scala 61:22 i2c_master.scala 62:15]
    node _GEN_60 = mux(_T_6, UInt<1>("h1"), _GEN_51) @[i2c_master.scala 61:22 i2c_master.scala 63:20]
    node _GEN_61 = mux(_T_6, intr_done, _GEN_52) @[i2c_master.scala 61:22 i2c_master.scala 30:28]
    node _GEN_62 = mux(_T_6, UInt<1>("h0"), _GEN_54) @[i2c_master.scala 61:22 i2c_master.scala 43:14]
    node _GEN_63 = mux(_T_6, UInt<1>("h0"), _GEN_55) @[i2c_master.scala 61:22 i2c_master.scala 44:13]
    node _GEN_64 = mux(_T_6, saved_addr, _GEN_56) @[i2c_master.scala 61:22 i2c_master.scala 27:29]
    node _GEN_65 = mux(_T_6, saved_data, _GEN_57) @[i2c_master.scala 61:22 i2c_master.scala 28:29]
    node _GEN_66 = mux(_T_6, count, _GEN_58) @[i2c_master.scala 61:22 i2c_master.scala 26:24]
    node WACK1 = UInt<1>("h0")
    node WACK2 = UInt<1>("h0")
    io_i2c_sda <= _GEN_60
    io_i2c_scl <= _io_i2c_scl_T_2 @[i2c_master.scala 49:16]
    io_ready <= _GEN_62
    io_stop <= _GEN_63
    io_i2c_intr <= intr_done @[i2c_master.scala 165:17]
    state <= mux(reset, UInt<8>("h0"), _GEN_59) @[i2c_master.scala 25:24 i2c_master.scala 25:24]
    count <= mux(reset, UInt<15>("h0"), _GEN_66) @[i2c_master.scala 26:24 i2c_master.scala 26:24]
    saved_addr <= mux(reset, UInt<7>("h0"), _GEN_64) @[i2c_master.scala 27:29 i2c_master.scala 27:29]
    saved_data <= mux(reset, UInt<8>("h0"), _GEN_65) @[i2c_master.scala 28:29 i2c_master.scala 28:29]
    i2c_scl_enable <= mux(reset, UInt<1>("h1"), _GEN_1) @[i2c_master.scala 29:33 i2c_master.scala 29:33]
    intr_done <= mux(reset, UInt<1>("h0"), _GEN_61) @[i2c_master.scala 30:28 i2c_master.scala 30:28]
    WACK11 <= mux(reset, UInt<1>("h0"), WACK11) @[i2c_master.scala 35:25 i2c_master.scala 35:25 i2c_master.scala 35:25]
    WACK22 <= mux(reset, UInt<1>("h0"), WACK22) @[i2c_master.scala 36:25 i2c_master.scala 36:25 i2c_master.scala 36:25]

  module I2C_Top :
    input clock : Clock
    input reset : UInt<1>
    input io_wdata : UInt<32>
    input io_addr : UInt<7>
    input io_ren : UInt<1>
    input io_we : UInt<1>
    input io_sda_in : UInt<1>
    output io_sda : UInt<1>
    output io_scl : UInt<1>
    output io_intr : UInt<1>

    inst i2c of i2c_master @[I2C_Top.scala 58:21]
    reg addr_start_bit : UInt<1>, clock with :
      reset => (UInt<1>("h0"), addr_start_bit) @[I2C_Top.scala 27:33]
    reg addr_slave_addr : UInt<7>, clock with :
      reset => (UInt<1>("h0"), addr_slave_addr) @[I2C_Top.scala 28:34]
    reg addr_data : UInt<8>, clock with :
      reset => (UInt<1>("h0"), addr_data) @[I2C_Top.scala 29:28]
    reg addr_read_write_bit : UInt<1>, clock with :
      reset => (UInt<1>("h0"), addr_read_write_bit) @[I2C_Top.scala 30:38]
    reg addr_sda_in : UInt<1>, clock with :
      reset => (UInt<1>("h0"), addr_sda_in) @[I2C_Top.scala 31:30]
    node _T = eq(io_ren, UInt<1>("h0")) @[I2C_Top.scala 36:10]
    node _T_1 = and(_T, io_we) @[I2C_Top.scala 36:20]
    node _T_2 = eq(io_addr, UInt<1>("h0")) @[I2C_Top.scala 37:18]
    node _addr_start_bit_T = bits(io_wdata, 0, 0) @[I2C_Top.scala 38:35]
    node _T_3 = eq(io_addr, UInt<3>("h4")) @[I2C_Top.scala 39:24]
    node _addr_slave_addr_T = bits(io_wdata, 6, 0) @[I2C_Top.scala 40:36]
    node _T_4 = eq(io_addr, UInt<5>("h10")) @[I2C_Top.scala 41:24]
    node _addr_data_T = bits(io_wdata, 7, 0) @[I2C_Top.scala 42:30]
    node _T_5 = eq(io_addr, UInt<4>("h8")) @[I2C_Top.scala 43:24]
    node _addr_read_write_bit_T = bits(io_wdata, 0, 0) @[I2C_Top.scala 44:40]
    node _T_6 = eq(io_addr, UInt<4>("hc")) @[I2C_Top.scala 45:24]
    node _addr_sda_in_T = bits(io_wdata, 0, 0) @[I2C_Top.scala 46:33]
    node _GEN_0 = mux(_T_6, _addr_sda_in_T, addr_sda_in) @[I2C_Top.scala 45:40 I2C_Top.scala 46:22 I2C_Top.scala 31:30]
    node _GEN_1 = mux(_T_6, addr_start_bit, UInt<1>("h0")) @[I2C_Top.scala 45:40 I2C_Top.scala 27:33 I2C_Top.scala 50:24]
    node _GEN_2 = mux(_T_6, addr_slave_addr, UInt<1>("h0")) @[I2C_Top.scala 45:40 I2C_Top.scala 28:34 I2C_Top.scala 51:25]
    node _GEN_3 = mux(_T_6, addr_data, UInt<1>("h0")) @[I2C_Top.scala 45:40 I2C_Top.scala 29:28 I2C_Top.scala 52:19]
    node _GEN_4 = mux(_T_5, _addr_read_write_bit_T, addr_read_write_bit) @[I2C_Top.scala 43:48 I2C_Top.scala 44:29 I2C_Top.scala 30:38]
    node _GEN_5 = mux(_T_5, addr_sda_in, _GEN_0) @[I2C_Top.scala 43:48 I2C_Top.scala 31:30]
    node _GEN_6 = mux(_T_5, addr_start_bit, _GEN_1) @[I2C_Top.scala 43:48 I2C_Top.scala 27:33]
    node _GEN_7 = mux(_T_5, addr_slave_addr, _GEN_2) @[I2C_Top.scala 43:48 I2C_Top.scala 28:34]
    node _GEN_8 = mux(_T_5, addr_data, _GEN_3) @[I2C_Top.scala 43:48 I2C_Top.scala 29:28]
    node _GEN_9 = mux(_T_4, _addr_data_T, _GEN_8) @[I2C_Top.scala 41:38 I2C_Top.scala 42:19]
    node _GEN_10 = mux(_T_4, addr_read_write_bit, _GEN_4) @[I2C_Top.scala 41:38 I2C_Top.scala 30:38]
    node _GEN_11 = mux(_T_4, addr_sda_in, _GEN_5) @[I2C_Top.scala 41:38 I2C_Top.scala 31:30]
    node _GEN_12 = mux(_T_4, addr_start_bit, _GEN_6) @[I2C_Top.scala 41:38 I2C_Top.scala 27:33]
    node _GEN_13 = mux(_T_4, addr_slave_addr, _GEN_7) @[I2C_Top.scala 41:38 I2C_Top.scala 28:34]
    node _GEN_14 = mux(_T_3, _addr_slave_addr_T, _GEN_13) @[I2C_Top.scala 39:44 I2C_Top.scala 40:25]
    node _GEN_15 = mux(_T_3, addr_data, _GEN_9) @[I2C_Top.scala 39:44 I2C_Top.scala 29:28]
    node _GEN_16 = mux(_T_3, addr_read_write_bit, _GEN_10) @[I2C_Top.scala 39:44 I2C_Top.scala 30:38]
    node _GEN_17 = mux(_T_3, addr_sda_in, _GEN_11) @[I2C_Top.scala 39:44 I2C_Top.scala 31:30]
    node _GEN_18 = mux(_T_3, addr_start_bit, _GEN_12) @[I2C_Top.scala 39:44 I2C_Top.scala 27:33]
    node _GEN_19 = mux(_T_2, _addr_start_bit_T, _GEN_18) @[I2C_Top.scala 37:37 I2C_Top.scala 38:24]
    node _GEN_20 = mux(_T_2, addr_slave_addr, _GEN_14) @[I2C_Top.scala 37:37 I2C_Top.scala 28:34]
    node _GEN_21 = mux(_T_2, addr_data, _GEN_15) @[I2C_Top.scala 37:37 I2C_Top.scala 29:28]
    node _GEN_22 = mux(_T_2, addr_read_write_bit, _GEN_16) @[I2C_Top.scala 37:37 I2C_Top.scala 30:38]
    node _GEN_23 = mux(_T_2, addr_sda_in, _GEN_17) @[I2C_Top.scala 37:37 I2C_Top.scala 31:30]
    node _GEN_24 = mux(_T_1, _GEN_19, addr_start_bit) @[I2C_Top.scala 36:29 I2C_Top.scala 27:33]
    node _GEN_25 = mux(_T_1, _GEN_20, addr_slave_addr) @[I2C_Top.scala 36:29 I2C_Top.scala 28:34]
    node _GEN_26 = mux(_T_1, _GEN_21, addr_data) @[I2C_Top.scala 36:29 I2C_Top.scala 29:28]
    node _GEN_27 = mux(_T_1, _GEN_22, addr_read_write_bit) @[I2C_Top.scala 36:29 I2C_Top.scala 30:38]
    node _GEN_28 = mux(_T_1, _GEN_23, addr_sda_in) @[I2C_Top.scala 36:29 I2C_Top.scala 31:30]
    io_sda <= i2c.io_i2c_sda @[I2C_Top.scala 66:12]
    io_scl <= i2c.io_i2c_scl @[I2C_Top.scala 67:12]
    io_intr <= i2c.io_i2c_intr @[I2C_Top.scala 68:13]
    addr_start_bit <= mux(reset, UInt<1>("h0"), _GEN_24) @[I2C_Top.scala 27:33 I2C_Top.scala 27:33]
    addr_slave_addr <= mux(reset, UInt<7>("h0"), _GEN_25) @[I2C_Top.scala 28:34 I2C_Top.scala 28:34]
    addr_data <= mux(reset, UInt<8>("h0"), _GEN_26) @[I2C_Top.scala 29:28 I2C_Top.scala 29:28]
    addr_read_write_bit <= mux(reset, UInt<1>("h0"), _GEN_27) @[I2C_Top.scala 30:38 I2C_Top.scala 30:38]
    addr_sda_in <= mux(reset, UInt<1>("h0"), _GEN_28) @[I2C_Top.scala 31:30 I2C_Top.scala 31:30]
    i2c.clock <= clock
    i2c.reset <= reset
    i2c.io_start <= addr_start_bit @[I2C_Top.scala 59:18]
    i2c.io_addr <= addr_slave_addr @[I2C_Top.scala 60:17]
    i2c.io_data <= addr_data @[I2C_Top.scala 61:17]
    i2c.io_read_write <= addr_read_write_bit @[I2C_Top.scala 62:23]
    i2c.io_i2c_sda_in <= addr_sda_in @[I2C_Top.scala 63:23]

  module i2c :
    input clock : Clock
    input reset : UInt<1>
    output io_request_ready : UInt<1>
    input io_request_valid : UInt<1>
    input io_request_bits_addrRequest : UInt<32>
    input io_request_bits_dataRequest : UInt<32>
    input io_request_bits_activeByteLane : UInt<4>
    input io_request_bits_isWrite : UInt<1>
    input io_response_ready : UInt<1>
    output io_response_valid : UInt<1>
    output io_response_bits_dataResponse : UInt<32>
    output io_response_bits_error : UInt<1>
    input io_cio_i2c_sda_in : UInt<1>
    output io_cio_i2c_sda : UInt<1>
    output io_cio_i2c_scl : UInt<1>
    output io_cio_i2c_intr : UInt<1>

    inst i2c_top of I2C_Top @[i2c.scala 18:26]
    node _write_register_T = and(io_request_ready, io_request_valid) @[Decoupled.scala 40:37]
    node _write_register_T_1 = mux(_write_register_T, io_request_bits_isWrite, UInt<1>("h0")) @[i2c.scala 25:26]
    node _read_register_T = and(io_request_ready, io_request_valid) @[Decoupled.scala 40:37]
    node _read_register_T_1 = eq(io_request_bits_isWrite, UInt<1>("h0")) @[i2c.scala 26:45]
    node _read_register_T_2 = mux(_read_register_T, _read_register_T_1, UInt<1>("h0")) @[i2c.scala 26:25]
    node _addr_reg_T = bits(io_request_bits_addrRequest, 6, 0) @[i2c.scala 28:44]
    node _io_response_bits_dataResponse_T = mux(io_response_ready, i2c_top.io_wdata, UInt<1>("h0")) @[i2c.scala 34:49]
    reg io_response_bits_dataResponse_REG : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_response_bits_dataResponse_REG) @[i2c.scala 34:45]
    node write_register = _write_register_T_1 @[i2c.scala 21:46 i2c.scala 25:20]
    node read_register = _read_register_T_2 @[i2c.scala 21:46 i2c.scala 26:19]
    node _io_response_valid_T = or(write_register, read_register) @[i2c.scala 35:53]
    node _io_response_valid_T_1 = mux(_io_response_valid_T, UInt<1>("h1"), UInt<1>("h0")) @[i2c.scala 35:37]
    reg io_response_valid_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_response_valid_REG) @[i2c.scala 35:33]
    node _io_response_bits_error_T = mux(io_response_ready, i2c_top.io_intr, UInt<1>("h0")) @[i2c.scala 36:42]
    reg io_response_bits_error_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_response_bits_error_REG) @[i2c.scala 36:38]
    node data_reg = io_request_bits_dataRequest @[i2c.scala 22:24 i2c.scala 27:14]
    node addr_reg = pad(_addr_reg_T, 8) @[i2c.scala 23:24 i2c.scala 28:14]
    io_request_ready <= UInt<1>("h1") @[i2c.scala 16:22]
    io_response_valid <= io_response_valid_REG @[i2c.scala 35:23]
    io_response_bits_dataResponse <= io_response_bits_dataResponse_REG @[i2c.scala 34:35]
    io_response_bits_error <= io_response_bits_error_REG @[i2c.scala 36:28]
    io_cio_i2c_sda <= i2c_top.io_sda @[i2c.scala 40:20]
    io_cio_i2c_scl <= i2c_top.io_scl @[i2c.scala 41:20]
    io_cio_i2c_intr <= i2c_top.io_intr @[i2c.scala 42:21]
    i2c_top.clock <= clock
    i2c_top.reset <= reset
    i2c_top.io_wdata <= data_reg @[i2c.scala 29:22]
    i2c_top.io_addr <= bits(addr_reg, 6, 0) @[i2c.scala 30:21]
    i2c_top.io_ren <= read_register @[i2c.scala 32:20]
    i2c_top.io_we <= write_register @[i2c.scala 31:19]
    i2c_top.io_sda_in <= io_cio_i2c_sda_in @[i2c.scala 38:23]
    io_response_bits_dataResponse_REG <= _io_response_bits_dataResponse_T @[i2c.scala 34:45]
    io_response_valid_REG <= _io_response_valid_T_1 @[i2c.scala 35:33]
    io_response_bits_error_REG <= _io_response_bits_error_T @[i2c.scala 36:38]

  module i2cHarness :
    input clock : Clock
    input reset : UInt<1>
    output io_request_ready : UInt<1>
    input io_request_valid : UInt<1>
    input io_request_bits_addrRequest : UInt<32>
    input io_request_bits_dataRequest : UInt<32>
    input io_request_bits_activeByteLane : UInt<4>
    input io_request_bits_isWrite : UInt<1>
    input io_response_ready : UInt<1>
    output io_response_valid : UInt<1>
    output io_response_bits_dataResponse : UInt<32>
    output io_response_bits_error : UInt<1>
    input io_i2c_sda_in : UInt<1>
    output io_i2c_sda : UInt<1>
    output io_i2c_scl : UInt<1>
    output io_i2c_intr : UInt<1>

    inst hostAdapter of WishboneHost @[i2cHarness.scala 24:27]
    inst deviceAdapter of WishboneDevice @[i2cHarness.scala 25:29]
    inst i2c_wrapper of i2c @[i2cHarness.scala 26:27]
    io_request_ready <= hostAdapter.io_reqIn_ready @[i2cHarness.scala 28:24]
    io_response_valid <= hostAdapter.io_rspOut_valid @[i2cHarness.scala 29:15]
    io_response_bits_dataResponse <= hostAdapter.io_rspOut_bits_dataResponse @[i2cHarness.scala 29:15]
    io_response_bits_error <= hostAdapter.io_rspOut_bits_error @[i2cHarness.scala 29:15]
    io_i2c_sda <= i2c_wrapper.io_cio_i2c_sda @[i2cHarness.scala 37:16]
    io_i2c_scl <= i2c_wrapper.io_cio_i2c_scl @[i2cHarness.scala 38:16]
    io_i2c_intr <= i2c_wrapper.io_cio_i2c_intr @[i2cHarness.scala 39:17]
    hostAdapter.clock <= clock
    hostAdapter.reset <= reset
    hostAdapter.io_wbMasterTransmitter_ready <= deviceAdapter.io_wbMasterReceiver_ready @[i2cHarness.scala 30:38]
    hostAdapter.io_wbSlaveReceiver_valid <= deviceAdapter.io_wbSlaveTransmitter_valid @[i2cHarness.scala 31:34]
    hostAdapter.io_wbSlaveReceiver_bits_ack <= deviceAdapter.io_wbSlaveTransmitter_bits_ack @[i2cHarness.scala 31:34]
    hostAdapter.io_wbSlaveReceiver_bits_dat <= deviceAdapter.io_wbSlaveTransmitter_bits_dat @[i2cHarness.scala 31:34]
    hostAdapter.io_wbSlaveReceiver_bits_err <= deviceAdapter.io_wbSlaveTransmitter_bits_err @[i2cHarness.scala 31:34]
    hostAdapter.io_reqIn_valid <= io_request_valid @[i2cHarness.scala 28:24]
    hostAdapter.io_reqIn_bits_addrRequest <= io_request_bits_addrRequest @[i2cHarness.scala 28:24]
    hostAdapter.io_reqIn_bits_dataRequest <= io_request_bits_dataRequest @[i2cHarness.scala 28:24]
    hostAdapter.io_reqIn_bits_activeByteLane <= io_request_bits_activeByteLane @[i2cHarness.scala 28:24]
    hostAdapter.io_reqIn_bits_isWrite <= io_request_bits_isWrite @[i2cHarness.scala 28:24]
    hostAdapter.io_rspOut_ready <= io_response_ready @[i2cHarness.scala 29:15]
    deviceAdapter.clock <= clock
    deviceAdapter.reset <= reset
    deviceAdapter.io_wbSlaveTransmitter_ready <= hostAdapter.io_wbSlaveReceiver_ready @[i2cHarness.scala 31:34]
    deviceAdapter.io_wbMasterReceiver_valid <= hostAdapter.io_wbMasterTransmitter_valid @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_cyc <= hostAdapter.io_wbMasterTransmitter_bits_cyc @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_stb <= hostAdapter.io_wbMasterTransmitter_bits_stb @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_we <= hostAdapter.io_wbMasterTransmitter_bits_we @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_adr <= hostAdapter.io_wbMasterTransmitter_bits_adr @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_dat <= hostAdapter.io_wbMasterTransmitter_bits_dat @[i2cHarness.scala 30:38]
    deviceAdapter.io_wbMasterReceiver_bits_sel <= hostAdapter.io_wbMasterTransmitter_bits_sel @[i2cHarness.scala 30:38]
    deviceAdapter.io_reqOut_ready <= i2c_wrapper.io_request_ready @[i2cHarness.scala 33:26]
    deviceAdapter.io_rspIn_valid <= i2c_wrapper.io_response_valid @[i2cHarness.scala 34:27]
    deviceAdapter.io_rspIn_bits_dataResponse <= i2c_wrapper.io_response_bits_dataResponse @[i2cHarness.scala 34:27]
    deviceAdapter.io_rspIn_bits_error <= i2c_wrapper.io_response_bits_error @[i2cHarness.scala 34:27]
    i2c_wrapper.clock <= clock
    i2c_wrapper.reset <= reset
    i2c_wrapper.io_request_valid <= deviceAdapter.io_reqOut_valid @[i2cHarness.scala 33:26]
    i2c_wrapper.io_request_bits_addrRequest <= deviceAdapter.io_reqOut_bits_addrRequest @[i2cHarness.scala 33:26]
    i2c_wrapper.io_request_bits_dataRequest <= deviceAdapter.io_reqOut_bits_dataRequest @[i2cHarness.scala 33:26]
    i2c_wrapper.io_request_bits_activeByteLane <= deviceAdapter.io_reqOut_bits_activeByteLane @[i2cHarness.scala 33:26]
    i2c_wrapper.io_request_bits_isWrite <= deviceAdapter.io_reqOut_bits_isWrite @[i2cHarness.scala 33:26]
    i2c_wrapper.io_response_ready <= deviceAdapter.io_rspIn_ready @[i2cHarness.scala 34:27]
    i2c_wrapper.io_cio_i2c_sda_in <= io_i2c_sda_in @[i2cHarness.scala 36:35]
