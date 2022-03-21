module i2c(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_read_write,
  input        io_ack,
  input        io_data_ack,
  output       io_i2c_sda,
  output       io_i2c_scl,
  output       io_ready,
  output       io_stop
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c.scala 25:24]
  reg [14:0] count; // @[i2c.scala 26:24]
  reg [6:0] saved_addr; // @[i2c.scala 27:29]
  reg [7:0] saved_data; // @[i2c.scala 28:29]
  reg  i2c_scl_enable; // @[i2c.scala 29:33]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h6 ? 1'h0 : 1'h1; // @[i2c.scala 53:87 i2c.scala 54:28 i2c.scala 56:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c.scala 50:22 i2c.scala 51:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c.scala 67:39 i2c.scala 68:27 i2c.scala 72:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = saved_addr >> count; // @[i2c.scala 88:41]
  wire  _T_11 = count == 15'h0; // @[i2c.scala 91:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c.scala 94:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c.scala 91:36 i2c.scala 92:27 i2c.scala 95:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c.scala 91:36 i2c.scala 26:24 i2c.scala 94:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _GEN_6 = ~io_read_write ? 1'h0 : 1'h1; // @[i2c.scala 101:44 i2c.scala 102:32 i2c.scala 108:32]
  wire [3:0] _GEN_9 = ~io_read_write ? 4'h8 : 4'h7; // @[i2c.scala 101:44 i2c.scala 106:27 i2c.scala 112:27]
  wire  _T_14 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = saved_data >> count; // @[i2c.scala 119:41]
  wire [2:0] _GEN_10 = _T_11 ? 3'h5 : 3'h4; // @[i2c.scala 122:36 i2c.scala 123:27 i2c.scala 126:27]
  wire  _T_16 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire  _GEN_15 = _T_16 ? io_data_ack : 1'h1; // @[Conditional.scala 39:67 i2c.scala 132:28]
  wire [2:0] _GEN_17 = _T_16 ? 3'h6 : 3'h0; // @[Conditional.scala 39:67 i2c.scala 135:23]
  wire  _GEN_18 = _T_14 ? _io_i2c_sda_T_2[0] : _GEN_15; // @[Conditional.scala 39:67 i2c.scala 119:28]
  wire [2:0] _GEN_20 = _T_14 ? _GEN_10 : _GEN_17; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_21 = _T_14 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c.scala 26:24]
  wire  _GEN_22 = _T_12 ? _GEN_6 : _GEN_18; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_24 = _T_12 ? 3'h4 : _GEN_20; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_25 = _T_12 ? {{11'd0}, _GEN_9} : _GEN_21; // @[Conditional.scala 39:67]
  wire  _GEN_26 = _T_10 ? _io_i2c_sda_T[0] : _GEN_22; // @[Conditional.scala 39:67 i2c.scala 88:28]
  wire [2:0] _GEN_28 = _T_10 ? _GEN_4 : _GEN_24; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_29 = _T_10 ? _GEN_5 : _GEN_25; // @[Conditional.scala 39:67]
  wire  _GEN_30 = _T_9 ? 1'h0 : _GEN_26; // @[Conditional.scala 39:67 i2c.scala 78:28]
  wire [2:0] _GEN_35 = _T_9 ? 3'h2 : _GEN_28; // @[Conditional.scala 39:67 i2c.scala 83:23]
  wire  _GEN_37 = _T_7 | _GEN_30; // @[Conditional.scala 40:58 i2c.scala 66:28]
  wire [2:0] _GEN_38 = _T_7 ? _GEN_2 : _GEN_35; // @[Conditional.scala 40:58]
  wire  _GEN_39 = _T_7 ? 1'h0 : _T_9; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_44 = reset ? 3'h0 : _GEN_38; // @[i2c.scala 60:22 i2c.scala 61:15]
  assign io_i2c_sda = reset | _GEN_37; // @[i2c.scala 60:22 i2c.scala 62:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c.scala 48:22]
  assign io_ready = reset ? 1'h0 : _GEN_39; // @[i2c.scala 60:22 i2c.scala 42:14]
  assign io_stop = 1'h0; // @[i2c.scala 60:22 i2c.scala 43:13]
  always @(posedge clock) begin
    if (reset) begin // @[i2c.scala 25:24]
      state <= 8'h0; // @[i2c.scala 25:24]
    end else begin
      state <= {{5'd0}, _GEN_44};
    end
    if (reset) begin // @[i2c.scala 26:24]
      count <= 15'h0; // @[i2c.scala 26:24]
    end else if (!(reset)) begin // @[i2c.scala 60:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c.scala 84:23]
        end else begin
          count <= _GEN_29;
        end
      end
    end
    if (reset) begin // @[i2c.scala 27:29]
      saved_addr <= 7'h0; // @[i2c.scala 27:29]
    end else if (!(reset)) begin // @[i2c.scala 60:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          saved_addr <= io_addr; // @[i2c.scala 79:28]
        end
      end
    end
    if (reset) begin // @[i2c.scala 28:29]
      saved_data <= 8'h0; // @[i2c.scala 28:29]
    end else if (!(reset)) begin // @[i2c.scala 60:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          saved_data <= io_data; // @[i2c.scala 80:28]
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c.scala 29:33 i2c.scala 29:33]
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
  saved_data = _RAND_3[7:0];
  _RAND_4 = {1{`RANDOM}};
  i2c_scl_enable = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
