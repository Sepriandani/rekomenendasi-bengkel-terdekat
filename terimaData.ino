void terimaData(){
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& dataMega = jsonBuffer.parseObject(Serial);

  if (dataMega == JsonObject::invalid()) {
    jsonBuffer.clear();
    cekData = "Tidak Ada";
    return;
  }
  latitude =  dataMega["latitude"].as<String>();
  longitude = dataMega["longitude"].as<String>();
  
  cekData = "Ada";
}
