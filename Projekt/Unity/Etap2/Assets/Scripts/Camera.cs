using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    public Transform pivot;
    float speed = 50;
    // Start is called before the first frame update
    
    // Update is called once per frame
    void Update()
    {
        //transform.position = (pivot.position + (new Vector3(4, 2, 2)));
        //transform.rotation = pivot.rotation;
        //transform.LookAt(pivot);
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.RotateAround(pivot.transform.position, Vector3.up, speed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.RotateAround(pivot.transform.position, Vector3.up, -speed * Time.deltaTime);
        }
    }
}
