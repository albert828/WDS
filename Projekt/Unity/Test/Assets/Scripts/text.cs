using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class text : MonoBehaviour
{
    public TextMeshPro textToPrint;
    public Transform pivot;
    uint counter = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //var rotation = pivot.rotation;
        //rotation *= Quaternion.Euler(0, -90, 0);
        //transform.rotation = Quaternion.Slerp(transform.rotation, rotation, 1);
        ++counter;
        counter %= 1000;
        textToPrint.text = counter.ToString();
    }
}
