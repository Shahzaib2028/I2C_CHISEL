import chisel3._
import chisel3 . util._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class i2cTest extends FreeSpec with ChiselScalatestTester {

  "i2c TEST" in {
    test(new i2c_master()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>    

        // c.io.start.poke(0.B)
        // c.clock.step(100)
        val slave_addr = "b1111000".U
        val slave_data = "b10101011".U

        c.io.start.poke(1.B)
        c.io.addr.poke(slave_addr)
        c.io.data.poke(slave_data)
        c.io.read_write.poke(0.B)
        

        ///////////salve//////////
        // if(slave_addr == "b1010101".U){
            c.io.ack.poke(0.B)
        // } else{
        //     c.io.ack.poke(1.B)
        // }


        // if(slave_data == "b10101111".U){
            c.io.data_ack.poke(0.B)
        // } else{
        //     c.io.data_ack.poke(1.B)
        // }


        //c.io.start.poke(0.B)
        c.clock.step(50)
        c.io.start.poke(0.B)
        c.clock.step(50)






    }
  }
}