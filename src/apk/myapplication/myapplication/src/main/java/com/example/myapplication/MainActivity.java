package com.example.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button bt;
    private TextView tv;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bt = (Button)findViewById(R.id.button);
        bt.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View V){

                CserviceInterface.cservice();
                //Toast.makeText(MainActivity.this,"调用服务中...",Toast.LENGTH_LONG).show();
            }

        });
    }
}
