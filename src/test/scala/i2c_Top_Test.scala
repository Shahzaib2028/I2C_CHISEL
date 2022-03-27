import chisel3._
import chisel3 . util._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class i2c_Top_Test extends FreeSpec with ChiselScalatestTester {

  "i2c Top TEST" in {
    test(new I2C_Top()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>    

        // c.io.start.poke(0.B)
        // c.clock.step(100)
        // val slave_addr = "b1111000".U
        // val slave_data = "b10101011".U

        // c.io.start.poke(1.B)
        // c.io.addr.poke(slave_addr)
        // c.io.data.poke(slave_data)
        // c.io.read_write.poke(0.B)
        

        // ///////////salve//////////
        // // if(slave_addr == "b1010101".U){
        //     c.io.ack.poke(0.B)
        // // } else{
        // //     c.io.ack.poke(1.B)
        // // }


        // // if(slave_data == "b10101111".U){
        //     c.io.data_ack.poke(0.B)
        // // } else{
        // //     c.io.data_ack.poke(1.B)
        // // }


        // //c.io.start.poke(0.B)
        // c.clock.step(50)
        // c.io.start.poke(0.B)
        // c.clock.step(50)

        c.io.addr.poke(0.U)
        c.clock.step(1)
        c.io.wdata.poke(1.U)
        c.clock.step(1)

        c.io.addr.poke(4.U)   
        c.clock.step(1) 
        c.io.wdata.poke(99.U)   //1100011
        c.clock.step(1)

        

        c.io.addr.poke(8.U)
        c.clock.step(1)
        c.io.wdata.poke(0.U)
        c.clock.step(1)

        c.io.addr.poke(12.U)
        c.clock.step(1)
        c.io.wdata.poke(0.U)
        c.clock.step(1)

        c.io.addr.poke(16.U)
        c.clock.step(1)
        c.io.wdata.poke(135.U) //10000111
        c.clock.step(1)

        



        c.io.addr.poke(20.U)
        c.clock.step(1)
        c.io.wdata.poke(0.U)
        c.clock.step(1)


        c.clock.step(50)






    }
  }
}