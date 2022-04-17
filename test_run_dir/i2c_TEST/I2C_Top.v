module i2c_master(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_i2c_sda_in,
  output       io_i2c_sda,
  output       io_i2c_scl,
  output       io_ready,
  output       io_stop,
  output       io_i2c_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c_master.scala 24:24]
  reg [14:0] count; // @[i2c_master.scala 25:24]
  reg [6:0] saved_addr; // @[i2c_master.scala 26:29]
  reg  i2c_scl_enable; // @[i2c_master.scala 28:33]
  reg  intr_done; // @[i2c_master.scala 29:28]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h7 ? 1'h0 : 1'h1; // @[i2c_master.scala 45:87 i2c_master.scala 46:28 i2c_master.scala 48:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c_master.scala 42:22 i2c_master.scala 43:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c_master.scala 60:39 i2c_master.scala 61:27 i2c_master.scala 65:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = saved_addr >> count; // @[i2c_master.scala 81:41]
  wire  _T_11 = count == 15'h0; // @[i2c_master.scala 84:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c_master.scala 87:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c_master.scala 84:36 i2c_master.scala 85:27 i2c_master.scala 88:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c_master.scala 84:36 i2c_master.scala 25:24 i2c_master.scala 87:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _T_13 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_6 = ~io_i2c_sda_in ? 3'h5 : 3'h7; // @[i2c_master.scala 104:48 i2c_master.scala 105:31 i2c_master.scala 110:31]
  wire [14:0] _GEN_7 = ~io_i2c_sda_in ? 15'h7 : count; // @[i2c_master.scala 104:48 i2c_master.scala 106:31 i2c_master.scala 25:24]
  wire  _T_15 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = io_data >> count; // @[i2c_master.scala 119:38]
  wire [2:0] _GEN_9 = _T_11 ? 3'h6 : 3'h5; // @[i2c_master.scala 122:36 i2c_master.scala 123:27 i2c_master.scala 126:27]
  wire  _T_17 = 8'h6 == state; // @[Conditional.scala 37:30]
  wire  _T_18 = 8'h7 == state; // @[Conditional.scala 37:30]
  wire  _GEN_12 = _T_18 | intr_done; // @[Conditional.scala 39:67 i2c_master.scala 140:27 i2c_master.scala 29:28]
  wire  _GEN_16 = _T_17 ? io_i2c_sda_in : 1'h1; // @[Conditional.scala 39:67 i2c_master.scala 132:28]
  wire  _GEN_18 = _T_17 ? 1'h0 : _T_18; // @[Conditional.scala 39:67 i2c_master.scala 134:25]
  wire [2:0] _GEN_19 = _T_17 ? 3'h7 : 3'h0; // @[Conditional.scala 39:67 i2c_master.scala 135:23]
  wire  _GEN_20 = _T_17 ? intr_done : _GEN_12; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_21 = _T_15 ? _io_i2c_sda_T_2[0] : _GEN_16; // @[Conditional.scala 39:67 i2c_master.scala 119:28]
  wire  _GEN_23 = _T_15 ? 1'h0 : _GEN_18; // @[Conditional.scala 39:67 i2c_master.scala 121:25]
  wire [2:0] _GEN_24 = _T_15 ? _GEN_9 : _GEN_19; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_25 = _T_15 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c_master.scala 25:24]
  wire  _GEN_26 = _T_15 ? intr_done : _GEN_20; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_27 = _T_13 ? io_i2c_sda_in : _GEN_21; // @[Conditional.scala 39:67 i2c_master.scala 103:32]
  wire [2:0] _GEN_28 = _T_13 ? _GEN_6 : _GEN_24; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_29 = _T_13 ? _GEN_7 : _GEN_25; // @[Conditional.scala 39:67]
  wire  _GEN_31 = _T_13 ? 1'h0 : _GEN_23; // @[Conditional.scala 39:67]
  wire  _GEN_32 = _T_13 ? intr_done : _GEN_26; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_33 = _T_12 ? 1'h0 : _GEN_27; // @[Conditional.scala 39:67 i2c_master.scala 94:28]
  wire  _GEN_35 = _T_12 ? 1'h0 : _GEN_31; // @[Conditional.scala 39:67 i2c_master.scala 96:25]
  wire [2:0] _GEN_36 = _T_12 ? 3'h4 : _GEN_28; // @[Conditional.scala 39:67 i2c_master.scala 97:23]
  wire [14:0] _GEN_37 = _T_12 ? count : _GEN_29; // @[Conditional.scala 39:67 i2c_master.scala 25:24]
  wire  _GEN_38 = _T_12 ? intr_done : _GEN_32; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_39 = _T_10 ? _io_i2c_sda_T[0] : _GEN_33; // @[Conditional.scala 39:67 i2c_master.scala 81:28]
  wire  _GEN_41 = _T_10 ? 1'h0 : _GEN_35; // @[Conditional.scala 39:67 i2c_master.scala 83:25]
  wire [2:0] _GEN_42 = _T_10 ? _GEN_4 : _GEN_36; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_43 = _T_10 ? _GEN_5 : _GEN_37; // @[Conditional.scala 39:67]
  wire  _GEN_44 = _T_10 ? intr_done : _GEN_38; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_45 = _T_9 ? 1'h0 : _GEN_39; // @[Conditional.scala 39:67 i2c_master.scala 71:28]
  wire  _GEN_49 = _T_9 ? 1'h0 : _GEN_41; // @[Conditional.scala 39:67 i2c_master.scala 75:25]
  wire [2:0] _GEN_50 = _T_9 ? 3'h2 : _GEN_42; // @[Conditional.scala 39:67 i2c_master.scala 76:23]
  wire  _GEN_53 = _T_7 | _GEN_45; // @[Conditional.scala 40:58 i2c_master.scala 58:28]
  wire [2:0] _GEN_55 = _T_7 ? _GEN_2 : _GEN_50; // @[Conditional.scala 40:58]
  wire  _GEN_56 = _T_7 ? 1'h0 : _T_9; // @[Conditional.scala 40:58]
  wire  _GEN_57 = _T_7 ? 1'h0 : _GEN_49; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_61 = reset ? 3'h0 : _GEN_55; // @[i2c_master.scala 52:22 i2c_master.scala 53:15]
  assign io_i2c_sda = reset | _GEN_53; // @[i2c_master.scala 52:22 i2c_master.scala 54:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c_master.scala 40:22]
  assign io_ready = reset ? 1'h0 : _GEN_56; // @[i2c_master.scala 52:22 i2c_master.scala 34:14]
  assign io_stop = reset ? 1'h0 : _GEN_57; // @[i2c_master.scala 52:22 i2c_master.scala 35:13]
  assign io_i2c_intr = intr_done; // @[i2c_master.scala 148:17]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_master.scala 24:24]
      state <= 8'h0; // @[i2c_master.scala 24:24]
    end else begin
      state <= {{5'd0}, _GEN_61};
    end
    if (reset) begin // @[i2c_master.scala 25:24]
      count <= 15'h0; // @[i2c_master.scala 25:24]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c_master.scala 77:23]
        end else begin
          count <= _GEN_43;
        end
      end
    end
    if (reset) begin // @[i2c_master.scala 26:29]
      saved_addr <= 7'h0; // @[i2c_master.scala 26:29]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          saved_addr <= io_addr; // @[i2c_master.scala 72:28]
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c_master.scala 28:33 i2c_master.scala 28:33]
    if (reset) begin // @[i2c_master.scala 29:28]
      intr_done <= 1'h0; // @[i2c_master.scala 29:28]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (_T_7) begin // @[Conditional.scala 40:58]
        intr_done <= 1'h0; // @[i2c_master.scala 59:27]
      end else if (!(_T_9)) begin // @[Conditional.scala 39:67]
        intr_done <= _GEN_44;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  count = _RAND_1[14:0];
  _RAND_2 = {1{`RANDOM}};
  saved_addr = _RAND_2[6:0];
  _RAND_3 = {1{`RANDOM}};
  i2c_scl_enable = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  intr_done = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module i2c_slave(
  input        clock,
  input        reset,
  input        io_sda_in,
  input        io_ready,
  output       io_sda_out,
  output [7:0] io_data_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] count; // @[i2c_slave.scala 30:20]
  reg [7:0] rx_state; // @[i2c_slave.scala 31:23]
  reg  addr_bit1; // @[i2c_slave.scala 38:24]
  reg  addr_bit2; // @[i2c_slave.scala 39:24]
  reg  addr_bit3; // @[i2c_slave.scala 40:24]
  reg  addr_bit4; // @[i2c_slave.scala 41:24]
  reg  addr_bit5; // @[i2c_slave.scala 42:24]
  reg  addr_bit6; // @[i2c_slave.scala 43:24]
  reg  addr_bit7; // @[i2c_slave.scala 44:24]
  reg [6:0] complete_addr; // @[i2c_slave.scala 45:28]
  reg  data_bit1; // @[i2c_slave.scala 47:24]
  reg  data_bit2; // @[i2c_slave.scala 48:24]
  reg  data_bit3; // @[i2c_slave.scala 49:24]
  reg  data_bit4; // @[i2c_slave.scala 50:24]
  reg  data_bit5; // @[i2c_slave.scala 51:24]
  reg  data_bit6; // @[i2c_slave.scala 52:24]
  reg  data_bit7; // @[i2c_slave.scala 53:24]
  reg  data_bit8; // @[i2c_slave.scala 54:24]
  reg [7:0] data; // @[i2c_slave.scala 55:19]
  wire  _T = 8'h0 == rx_state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_0 = io_ready ? 3'h1 : 3'h0; // @[i2c_slave.scala 62:23 i2c_slave.scala 64:22 i2c_slave.scala 67:22]
  wire  _T_1 = 8'h1 == rx_state; // @[Conditional.scala 37:30]
  wire [7:0] _count_T_1 = count + 8'h1; // @[i2c_slave.scala 77:28]
  wire  _GEN_1 = rx_state == 8'h1 & count == 8'h1 ? io_sda_in : addr_bit1; // @[i2c_slave.scala 73:52 i2c_slave.scala 74:23 i2c_slave.scala 38:24]
  wire [2:0] _GEN_3 = rx_state == 8'h1 & count == 8'h1 ? 3'h0 : 3'h1; // @[i2c_slave.scala 73:52 i2c_slave.scala 33:10 i2c_slave.scala 78:22]
  wire  _GEN_4 = count == 8'h2 ? io_sda_in : addr_bit2; // @[i2c_slave.scala 82:28 i2c_slave.scala 83:23 i2c_slave.scala 39:24]
  wire [2:0] _GEN_6 = count == 8'h2 ? _GEN_3 : 3'h1; // @[i2c_slave.scala 82:28 i2c_slave.scala 86:22]
  wire  _GEN_7 = count == 8'h3 ? io_sda_in : addr_bit3; // @[i2c_slave.scala 90:28 i2c_slave.scala 91:23 i2c_slave.scala 40:24]
  wire [2:0] _GEN_8 = count == 8'h3 ? _GEN_6 : 3'h1; // @[i2c_slave.scala 90:28 i2c_slave.scala 93:22]
  wire  _GEN_10 = count == 8'h4 ? io_sda_in : addr_bit4; // @[i2c_slave.scala 98:28 i2c_slave.scala 99:23 i2c_slave.scala 41:24]
  wire [2:0] _GEN_11 = count == 8'h4 ? _GEN_8 : 3'h1; // @[i2c_slave.scala 98:28 i2c_slave.scala 101:22]
  wire  _GEN_13 = count == 8'h5 ? io_sda_in : addr_bit5; // @[i2c_slave.scala 106:28 i2c_slave.scala 107:23 i2c_slave.scala 42:24]
  wire [2:0] _GEN_14 = count == 8'h5 ? _GEN_11 : 3'h1; // @[i2c_slave.scala 106:28 i2c_slave.scala 109:22]
  wire  _GEN_16 = count == 8'h6 ? io_sda_in : addr_bit6; // @[i2c_slave.scala 114:28 i2c_slave.scala 115:23 i2c_slave.scala 43:24]
  wire [2:0] _GEN_17 = count == 8'h6 ? _GEN_14 : 3'h1; // @[i2c_slave.scala 114:28 i2c_slave.scala 117:22]
  wire  _GEN_19 = count == 8'h7 ? io_sda_in : addr_bit7; // @[i2c_slave.scala 123:28 i2c_slave.scala 124:23 i2c_slave.scala 44:24]
  wire [2:0] _GEN_20 = count == 8'h7 ? _GEN_17 : 3'h1; // @[i2c_slave.scala 123:28 i2c_slave.scala 126:22]
  wire [6:0] _complete_addr_T = {addr_bit1,addr_bit2,addr_bit3,addr_bit4,addr_bit5,addr_bit6,addr_bit7}; // @[Cat.scala 30:58]
  wire [2:0] _GEN_24 = count < 8'h8 ? _GEN_20 : 3'h2; // @[i2c_slave.scala 72:26 i2c_slave.scala 135:22]
  wire  _T_12 = 8'h2 == rx_state; // @[Conditional.scala 37:30]
  wire  _GEN_33 = complete_addr == 7'h63 ? 1'h0 : 1'h1; // @[i2c_slave.scala 142:47 i2c_slave.scala 143:24 i2c_slave.scala 146:24]
  wire [2:0] _GEN_34 = complete_addr == 7'h63 ? 3'h3 : 3'h4; // @[i2c_slave.scala 142:47 i2c_slave.scala 144:22 i2c_slave.scala 147:22]
  wire  _T_14 = 8'h3 == rx_state; // @[Conditional.scala 37:30]
  wire  _GEN_35 = rx_state == 8'h3 & count == 8'h8 ? io_sda_in : data_bit1; // @[i2c_slave.scala 156:52 i2c_slave.scala 157:23 i2c_slave.scala 47:24]
  wire [2:0] _GEN_37 = rx_state == 8'h3 & count == 8'h8 ? 3'h0 : 3'h3; // @[i2c_slave.scala 156:52 i2c_slave.scala 33:10 i2c_slave.scala 161:22]
  wire  _GEN_38 = count == 8'h9 ? io_sda_in : data_bit2; // @[i2c_slave.scala 164:28 i2c_slave.scala 165:23 i2c_slave.scala 48:24]
  wire [2:0] _GEN_40 = count == 8'h9 ? _GEN_37 : 3'h3; // @[i2c_slave.scala 164:28 i2c_slave.scala 169:22]
  wire  _GEN_41 = count == 8'ha ? io_sda_in : data_bit3; // @[i2c_slave.scala 172:29 i2c_slave.scala 173:23 i2c_slave.scala 49:24]
  wire [2:0] _GEN_43 = count == 8'ha ? _GEN_40 : 3'h3; // @[i2c_slave.scala 172:29 i2c_slave.scala 177:22]
  wire  _GEN_44 = count == 8'hb ? io_sda_in : data_bit4; // @[i2c_slave.scala 180:29 i2c_slave.scala 181:23 i2c_slave.scala 50:24]
  wire [2:0] _GEN_46 = count == 8'hb ? _GEN_43 : 3'h3; // @[i2c_slave.scala 180:29 i2c_slave.scala 185:22]
  wire  _GEN_47 = count == 8'hc ? io_sda_in : data_bit5; // @[i2c_slave.scala 188:29 i2c_slave.scala 189:23 i2c_slave.scala 51:24]
  wire [2:0] _GEN_49 = count == 8'hc ? _GEN_46 : 3'h3; // @[i2c_slave.scala 188:29 i2c_slave.scala 193:22]
  wire  _GEN_50 = count == 8'hd ? io_sda_in : data_bit6; // @[i2c_slave.scala 196:29 i2c_slave.scala 197:23 i2c_slave.scala 52:24]
  wire [2:0] _GEN_52 = count == 8'hd ? _GEN_49 : 3'h3; // @[i2c_slave.scala 196:29 i2c_slave.scala 201:22]
  wire  _GEN_53 = count == 8'he ? io_sda_in : data_bit7; // @[i2c_slave.scala 204:29 i2c_slave.scala 205:23 i2c_slave.scala 53:24]
  wire [2:0] _GEN_55 = count == 8'he ? _GEN_52 : 3'h3; // @[i2c_slave.scala 204:29 i2c_slave.scala 209:22]
  wire  _GEN_56 = count == 8'hf ? io_sda_in : data_bit8; // @[i2c_slave.scala 212:29 i2c_slave.scala 213:23 i2c_slave.scala 54:24]
  wire [2:0] _GEN_58 = count == 8'hf ? _GEN_55 : 3'h3; // @[i2c_slave.scala 212:29 i2c_slave.scala 217:22]
  wire [7:0] _data_T = {data_bit1,data_bit2,data_bit3,data_bit4,data_bit5,data_bit6,data_bit7,data_bit8}; // @[Cat.scala 30:58]
  wire  _GEN_59 = count < 8'h10 ? _GEN_35 : data_bit1; // @[i2c_slave.scala 154:27 i2c_slave.scala 47:24]
  wire [7:0] _GEN_60 = count < 8'h10 ? _count_T_1 : count; // @[i2c_slave.scala 154:27 i2c_slave.scala 220:15 i2c_slave.scala 30:20]
  wire [2:0] _GEN_61 = count < 8'h10 ? _GEN_58 : 3'h4; // @[i2c_slave.scala 154:27 i2c_slave.scala 225:22]
  wire  _GEN_62 = count < 8'h10 ? _GEN_38 : data_bit2; // @[i2c_slave.scala 154:27 i2c_slave.scala 48:24]
  wire  _GEN_63 = count < 8'h10 ? _GEN_41 : data_bit3; // @[i2c_slave.scala 154:27 i2c_slave.scala 49:24]
  wire  _GEN_64 = count < 8'h10 ? _GEN_44 : data_bit4; // @[i2c_slave.scala 154:27 i2c_slave.scala 50:24]
  wire  _GEN_65 = count < 8'h10 ? _GEN_47 : data_bit5; // @[i2c_slave.scala 154:27 i2c_slave.scala 51:24]
  wire  _GEN_66 = count < 8'h10 ? _GEN_50 : data_bit6; // @[i2c_slave.scala 154:27 i2c_slave.scala 52:24]
  wire  _GEN_67 = count < 8'h10 ? _GEN_53 : data_bit7; // @[i2c_slave.scala 154:27 i2c_slave.scala 53:24]
  wire  _GEN_68 = count < 8'h10 ? _GEN_56 : data_bit8; // @[i2c_slave.scala 154:27 i2c_slave.scala 54:24]
  wire [7:0] _GEN_69 = count < 8'h10 ? data : _data_T; // @[i2c_slave.scala 154:27 i2c_slave.scala 55:19 i2c_slave.scala 223:18]
  wire  _T_26 = 8'h4 == rx_state; // @[Conditional.scala 37:30]
  wire [7:0] _GEN_71 = _T_26 ? 8'h0 : count; // @[Conditional.scala 39:67 i2c_slave.scala 233:15 i2c_slave.scala 30:20]
  wire  _GEN_73 = _T_14 ? _GEN_59 : data_bit1; // @[Conditional.scala 39:67 i2c_slave.scala 47:24]
  wire [7:0] _GEN_74 = _T_14 ? _GEN_60 : _GEN_71; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_75 = _T_14 ? _GEN_61 : 3'h0; // @[Conditional.scala 39:67]
  wire  _GEN_76 = _T_14 ? _GEN_62 : data_bit2; // @[Conditional.scala 39:67 i2c_slave.scala 48:24]
  wire  _GEN_77 = _T_14 ? _GEN_63 : data_bit3; // @[Conditional.scala 39:67 i2c_slave.scala 49:24]
  wire  _GEN_78 = _T_14 ? _GEN_64 : data_bit4; // @[Conditional.scala 39:67 i2c_slave.scala 50:24]
  wire  _GEN_79 = _T_14 ? _GEN_65 : data_bit5; // @[Conditional.scala 39:67 i2c_slave.scala 51:24]
  wire  _GEN_80 = _T_14 ? _GEN_66 : data_bit6; // @[Conditional.scala 39:67 i2c_slave.scala 52:24]
  wire  _GEN_81 = _T_14 ? _GEN_67 : data_bit7; // @[Conditional.scala 39:67 i2c_slave.scala 53:24]
  wire  _GEN_82 = _T_14 ? _GEN_68 : data_bit8; // @[Conditional.scala 39:67 i2c_slave.scala 54:24]
  wire [7:0] _GEN_83 = _T_14 ? _GEN_69 : data; // @[Conditional.scala 39:67 i2c_slave.scala 55:19]
  wire [2:0] _GEN_86 = _T_12 ? _GEN_34 : _GEN_75; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_99 = _T_1 ? _GEN_24 : _GEN_86; // @[Conditional.scala 39:67]
  wire  _GEN_108 = _T_1 ? 1'h0 : _T_12 & _GEN_33; // @[Conditional.scala 39:67 i2c_slave.scala 35:12]
  wire [2:0] _GEN_117 = _T ? _GEN_0 : _GEN_99; // @[Conditional.scala 40:58]
  assign io_sda_out = _T ? 1'h0 : _GEN_108; // @[Conditional.scala 40:58 i2c_slave.scala 35:12]
  assign io_data_out = data; // @[i2c_slave.scala 242:13]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_slave.scala 30:20]
      count <= 8'h1; // @[i2c_slave.scala 30:20]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          count <= _count_T_1; // @[i2c_slave.scala 130:15]
        end
      end else if (!(_T_12)) begin // @[Conditional.scala 39:67]
        count <= _GEN_74;
      end
    end
    if (reset) begin // @[i2c_slave.scala 31:23]
      rx_state <= 8'h0; // @[i2c_slave.scala 31:23]
    end else begin
      rx_state <= {{5'd0}, _GEN_117};
    end
    if (reset) begin // @[i2c_slave.scala 38:24]
      addr_bit1 <= 1'h0; // @[i2c_slave.scala 38:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit1 <= _GEN_1;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 39:24]
      addr_bit2 <= 1'h0; // @[i2c_slave.scala 39:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit2 <= _GEN_4;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 40:24]
      addr_bit3 <= 1'h0; // @[i2c_slave.scala 40:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit3 <= _GEN_7;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 41:24]
      addr_bit4 <= 1'h0; // @[i2c_slave.scala 41:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit4 <= _GEN_10;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 42:24]
      addr_bit5 <= 1'h0; // @[i2c_slave.scala 42:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit5 <= _GEN_13;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 43:24]
      addr_bit6 <= 1'h0; // @[i2c_slave.scala 43:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit6 <= _GEN_16;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 44:24]
      addr_bit7 <= 1'h0; // @[i2c_slave.scala 44:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (count < 8'h8) begin // @[i2c_slave.scala 72:26]
          addr_bit7 <= _GEN_19;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 45:28]
      complete_addr <= 7'h0; // @[i2c_slave.scala 45:28]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (!(count < 8'h8)) begin // @[i2c_slave.scala 72:26]
          complete_addr <= _complete_addr_T; // @[i2c_slave.scala 133:27]
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 47:24]
      data_bit1 <= 1'h0; // @[i2c_slave.scala 47:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit1 <= _GEN_73;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 48:24]
      data_bit2 <= 1'h0; // @[i2c_slave.scala 48:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit2 <= _GEN_76;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 49:24]
      data_bit3 <= 1'h0; // @[i2c_slave.scala 49:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit3 <= _GEN_77;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 50:24]
      data_bit4 <= 1'h0; // @[i2c_slave.scala 50:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit4 <= _GEN_78;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 51:24]
      data_bit5 <= 1'h0; // @[i2c_slave.scala 51:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit5 <= _GEN_79;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 52:24]
      data_bit6 <= 1'h0; // @[i2c_slave.scala 52:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit6 <= _GEN_80;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 53:24]
      data_bit7 <= 1'h0; // @[i2c_slave.scala 53:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit7 <= _GEN_81;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 54:24]
      data_bit8 <= 1'h0; // @[i2c_slave.scala 54:24]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (!(_T_1)) begin // @[Conditional.scala 39:67]
        if (!(_T_12)) begin // @[Conditional.scala 39:67]
          data_bit8 <= _GEN_82;
        end
      end
    end
    if (reset) begin // @[i2c_slave.scala 55:19]
      data <= 8'h0; // @[i2c_slave.scala 55:19]
    end else if (!(_T)) begin // @[Conditional.scala 40:58]
      if (_T_1) begin // @[Conditional.scala 39:67]
        if (!(count < 8'h8)) begin // @[i2c_slave.scala 72:26]
          data <= 8'h0; // @[i2c_slave.scala 134:18]
        end
      end else if (!(_T_12)) begin // @[Conditional.scala 39:67]
        data <= _GEN_83;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  count = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  rx_state = _RAND_1[7:0];
  _RAND_2 = {1{`RANDOM}};
  addr_bit1 = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  addr_bit2 = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  addr_bit3 = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  addr_bit4 = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  addr_bit5 = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  addr_bit6 = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  addr_bit7 = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  complete_addr = _RAND_9[6:0];
  _RAND_10 = {1{`RANDOM}};
  data_bit1 = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  data_bit2 = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  data_bit3 = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  data_bit4 = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  data_bit5 = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  data_bit6 = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  data_bit7 = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  data_bit8 = _RAND_17[0:0];
  _RAND_18 = {1{`RANDOM}};
  data = _RAND_18[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module I2C_Top(
  input         clock,
  input         reset,
  input  [31:0] io_wdata,
  input  [6:0]  io_addr,
  input         io_ren,
  input         io_we,
  output        io_sda,
  output        io_scl,
  output        io_ready,
  output        io_stop,
  output [7:0]  io_data_out,
  output        io_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  wire  i2c_master_clock; // @[I2C_Top.scala 61:28]
  wire  i2c_master_reset; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_start; // @[I2C_Top.scala 61:28]
  wire [6:0] i2c_master_io_addr; // @[I2C_Top.scala 61:28]
  wire [7:0] i2c_master_io_data; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_i2c_sda_in; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_i2c_sda; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_i2c_scl; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_ready; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_stop; // @[I2C_Top.scala 61:28]
  wire  i2c_master_io_i2c_intr; // @[I2C_Top.scala 61:28]
  wire  i2c_slave_clock; // @[I2C_Top.scala 73:27]
  wire  i2c_slave_reset; // @[I2C_Top.scala 73:27]
  wire  i2c_slave_io_sda_in; // @[I2C_Top.scala 73:27]
  wire  i2c_slave_io_ready; // @[I2C_Top.scala 73:27]
  wire  i2c_slave_io_sda_out; // @[I2C_Top.scala 73:27]
  wire [7:0] i2c_slave_io_data_out; // @[I2C_Top.scala 73:27]
  reg  addr_start_bit; // @[I2C_Top.scala 30:33]
  reg [6:0] addr_slave_addr; // @[I2C_Top.scala 31:34]
  reg [7:0] addr_data; // @[I2C_Top.scala 32:28]
  wire  _GEN_1 = io_addr == 7'h8 & addr_start_bit; // @[I2C_Top.scala 46:48 I2C_Top.scala 30:33 I2C_Top.scala 53:24]
  wire [6:0] _GEN_2 = io_addr == 7'h8 ? addr_slave_addr : 7'h0; // @[I2C_Top.scala 46:48 I2C_Top.scala 31:34 I2C_Top.scala 54:25]
  wire [7:0] _GEN_3 = io_addr == 7'h8 ? addr_data : 8'h0; // @[I2C_Top.scala 46:48 I2C_Top.scala 32:28 I2C_Top.scala 55:19]
  wire [7:0] _GEN_4 = io_addr == 7'h10 ? io_wdata[7:0] : _GEN_3; // @[I2C_Top.scala 44:38 I2C_Top.scala 45:19]
  wire  _GEN_6 = io_addr == 7'h10 ? addr_start_bit : _GEN_1; // @[I2C_Top.scala 44:38 I2C_Top.scala 30:33]
  wire [6:0] _GEN_7 = io_addr == 7'h10 ? addr_slave_addr : _GEN_2; // @[I2C_Top.scala 44:38 I2C_Top.scala 31:34]
  i2c_master i2c_master ( // @[I2C_Top.scala 61:28]
    .clock(i2c_master_clock),
    .reset(i2c_master_reset),
    .io_start(i2c_master_io_start),
    .io_addr(i2c_master_io_addr),
    .io_data(i2c_master_io_data),
    .io_i2c_sda_in(i2c_master_io_i2c_sda_in),
    .io_i2c_sda(i2c_master_io_i2c_sda),
    .io_i2c_scl(i2c_master_io_i2c_scl),
    .io_ready(i2c_master_io_ready),
    .io_stop(i2c_master_io_stop),
    .io_i2c_intr(i2c_master_io_i2c_intr)
  );
  i2c_slave i2c_slave ( // @[I2C_Top.scala 73:27]
    .clock(i2c_slave_clock),
    .reset(i2c_slave_reset),
    .io_sda_in(i2c_slave_io_sda_in),
    .io_ready(i2c_slave_io_ready),
    .io_sda_out(i2c_slave_io_sda_out),
    .io_data_out(i2c_slave_io_data_out)
  );
  assign io_sda = i2c_master_io_i2c_sda; // @[I2C_Top.scala 66:12]
  assign io_scl = i2c_master_io_i2c_scl; // @[I2C_Top.scala 67:12]
  assign io_ready = i2c_master_io_ready; // @[I2C_Top.scala 69:14]
  assign io_stop = i2c_master_io_stop; // @[I2C_Top.scala 70:13]
  assign io_data_out = i2c_slave_io_data_out; // @[I2C_Top.scala 79:17]
  assign io_intr = i2c_master_io_i2c_intr; // @[I2C_Top.scala 68:13]
  assign i2c_master_clock = clock;
  assign i2c_master_reset = reset;
  assign i2c_master_io_start = addr_start_bit; // @[I2C_Top.scala 62:25]
  assign i2c_master_io_addr = addr_slave_addr; // @[I2C_Top.scala 63:24]
  assign i2c_master_io_data = addr_data; // @[I2C_Top.scala 64:24]
  assign i2c_master_io_i2c_sda_in = i2c_slave_io_sda_out; // @[I2C_Top.scala 78:30]
  assign i2c_slave_clock = clock;
  assign i2c_slave_reset = reset;
  assign i2c_slave_io_sda_in = i2c_master_io_i2c_sda; // @[I2C_Top.scala 74:25]
  assign i2c_slave_io_ready = i2c_master_io_ready; // @[I2C_Top.scala 75:24]
  always @(posedge clock) begin
    if (reset) begin // @[I2C_Top.scala 30:33]
      addr_start_bit <= 1'h0; // @[I2C_Top.scala 30:33]
    end else if (~io_ren & io_we) begin // @[I2C_Top.scala 39:29]
      if (io_addr == 7'h0) begin // @[I2C_Top.scala 40:37]
        addr_start_bit <= io_wdata[0]; // @[I2C_Top.scala 41:24]
      end else if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 42:44]
        addr_start_bit <= _GEN_6;
      end
    end
    if (reset) begin // @[I2C_Top.scala 31:34]
      addr_slave_addr <= 7'h0; // @[I2C_Top.scala 31:34]
    end else if (~io_ren & io_we) begin // @[I2C_Top.scala 39:29]
      if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 40:37]
        if (io_addr == 7'h4) begin // @[I2C_Top.scala 42:44]
          addr_slave_addr <= io_wdata[6:0]; // @[I2C_Top.scala 43:25]
        end else begin
          addr_slave_addr <= _GEN_7;
        end
      end
    end
    if (reset) begin // @[I2C_Top.scala 32:28]
      addr_data <= 8'h0; // @[I2C_Top.scala 32:28]
    end else if (~io_ren & io_we) begin // @[I2C_Top.scala 39:29]
      if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 40:37]
        if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 42:44]
          addr_data <= _GEN_4;
        end
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  addr_start_bit = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  addr_slave_addr = _RAND_1[6:0];
  _RAND_2 = {1{`RANDOM}};
  addr_data = _RAND_2[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
