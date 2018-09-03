package com.bruce.counter;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.InputType;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class oMainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native double stringFromC(String s);

    o
    private EditText screen;
    private Button add;
    private Button reduce;//  -
    private Button del;
    private Button one;
    private Button two;
    private Button three;
    private Button ride;// ×
    private Button four;
    private Button five;
    private Button six;
    private Button seven;
    private Button eight;
    private Button nine;
    private Button zero;
    private Button point;
    private Button equal;
    private Button divide;//  ÷

    private StringBuilder sb;
    private String displayStr;//从stringbuilder中获取的字符串
    boolean inputSign;//最后输入的是否是运算符
    boolean inputEqual;//输入等号

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sb = new StringBuilder();
        inputSign = true;
        initView();
        setEventListener();
    }

    private void setEventListener() {
        MyClickListener clickListener = new MyClickListener();
        add.setOnClickListener(clickListener);
        reduce.setOnClickListener(clickListener);
        del.setOnClickListener(clickListener);
        one.setOnClickListener(clickListener);
        two.setOnClickListener(clickListener);
        three.setOnClickListener(clickListener);
        ride.setOnClickListener(clickListener);
        four.setOnClickListener(clickListener);
        five.setOnClickListener(clickListener);
        six.setOnClickListener(clickListener);
        seven.setOnClickListener(clickListener);
        eight.setOnClickListener(clickListener);
        nine.setOnClickListener(clickListener);
        zero.setOnClickListener(clickListener);
        point.setOnClickListener(clickListener);
        equal.setOnClickListener(clickListener);
        divide.setOnClickListener(clickListener);
    }

    private void initView() {
        screen = (EditText) findViewById(R.id.screen);
        screen.setInputType(InputType.TYPE_NULL);
        add = (Button) findViewById(R.id.add);
        reduce = (Button) findViewById(R.id.reduce);
        del = (Button) findViewById(R.id.del);
        one = (Button) findViewById(R.id.one);
        two = (Button) findViewById(R.id.two);
        three = (Button) findViewById(R.id.three);
        ride = (Button) findViewById(R.id.ride);
        four = (Button) findViewById(R.id.four);
        five = (Button) findViewById(R.id.five);
        six = (Button) findViewById(R.id.six);
        seven = (Button) findViewById(R.id.seven);
        eight = (Button) findViewById(R.id.eight);
        nine = (Button) findViewById(R.id.nine);
        zero = (Button) findViewById(R.id.zero);
        point = (Button) findViewById(R.id.point);
        equal = (Button) findViewById(R.id.equal);
        divide = (Button) findViewById(R.id.divide);
    }

    class MyClickListener implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            Log.i(TAG, "onClick: ");
            switch (view.getId()) {
                case R.id.one:
                    sb.append(1);
                    inputEqual = false;
                    inputSign = false;
                    break;
                case R.id.two:
                    sb.append(2);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.three:
                    sb.append(3);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.four:
                    sb.append(4);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.five:
                    sb.append(5);
                    inputEqual = false;
                    inputSign = false;
                    break;
                case R.id.six:
                    sb.append(6);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.seven:
                    sb.append(7);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.eight:
                    sb.append(8);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.nine:
                    sb.append(9);
                    inputSign = false;
                    inputEqual = false;
                    break;
                case R.id.zero:
                    sb.append(0);
                    inputEqual = false;
                    inputSign = false;
                    break;
                case R.id.point:

                    inputEqual = false;
                    if (!inputSign) {
                        sb.append(".");
                        inputSign = true;
                    }
                    break;
                case R.id.del:
                    inputEqual = false;
                    inputSign=false;
                    if (sb.length() != 0) {
                        if (inputEqual) {
                            sb.delete(0, sb.length());
                        }
                        sb.deleteCharAt(sb.length() - 1);
                    }
                    break;
                case R.id.add:
                    inputEqual = false;
                    if (!inputSign) {
                        inputSign = true;
                        sb.append("+");
                    }
                    break;
                case R.id.reduce:
                    inputEqual = false;
                    if (!inputSign) {
                        inputSign = true;
                        sb.append("-");
                    }
                    break;
                case R.id.ride:
                    inputEqual = false;
                    if (!inputSign) {
                        inputSign = true;
                        sb.append("×");
                    }
                    break;
                case R.id.divide:
                    inputEqual = false;
                    if (!inputSign) {
                        inputSign = true;
                        sb.append("÷");
                    }
                    break;
                case R.id.equal:
                    inputEqual = true;
                    int length = sb.length();
                    if (length > 1) {
                        switch (sb.charAt(length - 1)) {
                            case '+':
                                sb.deleteCharAt(length - 1);
                                break;
                            case '-':
                                sb.deleteCharAt(length - 1);
                                break;
                            case '*':
                                sb.deleteCharAt(length - 1);
                                break;
                            case '/:
                                sb.deleteCharAt(length - 1);
                                break;
                            case '.':
                                sb.deleteCharAt(length - 1);
                                break;

                        }
                        displayStr = sb.toString();
                       // displayStr=displayStr.replace("×","*").replace("÷","/");
//                        screen.setText(displayStr);//计算结束更新屏幕
                        screen.setText(stringFromC(displayStr)+"");//计算结束更新屏幕
//                        Toast.makeText(MainActivity.this, displayStr, Toast.LENGTH_SHORT).show();
                        sb.delete(0, sb.length());
                    }
                    break;
            }
            if (!inputEqual) {
                displayStr = sb.toString();
                screen.setText(displayStr);
            }
        }
    }

}
