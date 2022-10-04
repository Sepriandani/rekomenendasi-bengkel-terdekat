void kirimFirebase(){
  if (millis() - dataMillis > 5000)
    {

    Firebase.setString(fbdo, "Longitude", longitude);
    Firebase.setString(fbdo, "Latitude", latitude);
    //Firebase.RTDB.setString(&fbdo, "Rotasi", rotasi);
    Firebase.setString(fbdo, "Tanggal", date);
  
  }
}
