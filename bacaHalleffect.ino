void bacaHallefect(){
 status1 = digitalRead(halleffect);
 //hitung =  EEPROM.read(0);
 if(status1 == HIGH){
    kondisi1 = 0;
 }else if (status1 == LOW && kondisi1 == 0){
     hitung++;
     kondisi1 = 0;
     hasil = (String)hitung;
//     EEPROM.write(0, hitung);
//     EEPROM.commit();
     rotasi = (String)hitung;

 }else if (status1 = LOW && kondisi1 == 1){
     kondisi1 = 1;

 }
}
