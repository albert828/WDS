using System.Collections;
using System.Collections.Generic;
using System;
using System.IO.Ports;
using System.Threading;
using UnityEngine;

public class abc : MonoBehaviour
{
    public static string arduino;
    static SerialPort _serialPort;
    // Start is called before the first frame update
    void Start()
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "COM4";//Set your board COM
        _serialPort.BaudRate = 2000000;
        _serialPort.ReadTimeout = 10;
        _serialPort.Open();
    }

    // Update is called once per frame
    void Update()
    {
        arduino = _serialPort.ReadLine();
        //Debug.Log(a);
    }
}
