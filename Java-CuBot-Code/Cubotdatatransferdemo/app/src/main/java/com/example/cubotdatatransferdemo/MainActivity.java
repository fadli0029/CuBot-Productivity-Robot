package com.example.cubotdatatransferdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;
import java.lang.Integer;

public class MainActivity extends AppCompatActivity {

    private final UUID mUUID = UUID.fromString("00001101-0000-1000-8000-00805F9834FB");

    /* These are for testing, put them in the write method in the try-catch */
    public static final byte zero_ascii = 48;
    public static final byte one_ascii = 49;
    public static final byte two_ascii = 50;
    public static final byte three_ascii = 51;
    public static final byte four_ascii = 52;
    public static final byte five_ascii = 53;
    public static final byte six_ascii = 54;
    public static final byte seven_ascii = 55;
    public static final byte eight_ascii = 56;
    public static final byte nine_ascii = 57;

    /* If the above sample data doesn't work, then we take integers and convert them into bytes */
    /* Example */
    Integer a = new Integer(10); // <- Note: you would have to take the value and convert to
                                       //          Integer object in order to use byteValue()
    byte b1 = a.byteValue();

    Integer c = new Integer(4); // <- Note: you would have to take the value and convert to
                                      //          Integer object in order to use byteValue()
    byte b2 = c.byteValue();

    Integer d = new Integer(5); // <- Note: you would have to take the value and convert to
                                      //          Integer object in order to use byteValue()
    byte b3 = d.byteValue();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();

        // we have the address of the CuBot
        BluetoothDevice hc05 = adapter.getRemoteDevice("00:14:03:05:09:79");

        BluetoothSocket mbtSocket = null;
        int counter = 0;
        do {

            try{
                mbtSocket = hc05.createRfcommSocketToServiceRecord(mUUID);
                mbtSocket.connect();
            }catch(IOException e){
                e.printStackTrace();
            }
            counter++;
        } while(!mbtSocket.isConnected() && counter < 3);


        try{
            OutputStream outputStream = mbtSocket.getOutputStream();
            outputStream.write(zero_ascii);
        }catch(IOException e){
            e.printStackTrace();
        }

        // We're only sending data out to the arduino, but we're not receiving anything in
        // So we don't need an InputStream
        /*
        try {
            InputStream inputStream = mbtSocket.getInputStream();
            inputStream.skip(inputStream.available());
        }catch(IOException e){
            e.printStackTrace();
        }
        */

        /* We have to close the socket after use */
        try{
            mbtSocket.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}