using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class text : MonoBehaviour
{
    public TextMeshPro textToPrint;
    uint counter = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        ++counter;
        counter %= 1000;
        textToPrint.text = counter.ToString();
    }
}
