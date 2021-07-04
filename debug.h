inline void printResources( float cpu, uint8_t mem) {
  SYNTH_COM.print( "CPU Usage: ");
  SYNTH_COM.print(cpu);
  SYNTH_COM.print( "%, Memory: ");
  SYNTH_COM.println(mem);
}

//void performanceCheck() {
//  static unsigned long last = 0;
//  unsigned long now = millis();
//  if ((now-last)>1000) {
//    last = now;
//    float cpu = AudioProcessorUsageMax();
//    uint8_t mem = AudioMemoryUsageMax();
//    if( (statsMem!=mem) || fabs(statsCpu-cpu)>1) {
//      printResources( cpu, mem);
//    }
//    AudioProcessorUsageMaxReset();
//    AudioMemoryUsageMaxReset();
//    last = now;
//    statsCpu = cpu;
//    statsMem = mem;
//  }
//}