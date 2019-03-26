using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class platformRotate : MonoBehaviour
{
    float speed = 50f;
    //public Transform holder;
    //public Transform cube1;
    //float previousRotation = 0;
    public Transform pivot;
    //public Transform cube;
    private Vector3 initialVector = Vector3.back;

    // Start is called before the first frame update
    void Start()
    {
        initialVector = transform.position - pivot.position;
        initialVector.z = 0;
    }

    // Update is called once per frame
    void Update()
    {
        //var holderRotation = holder.rotation.y;
        //Rigidbody cube = cube1.GetComponent<Rigidbody>();
        //transform.rotation = holder.rotation;
        float rotateDegrees = 0f;
        if (Input.GetKey(KeyCode.UpArrow))
        {
            transform.RotateAround(pivot.transform.position, transform.TransformDirection(Vector3.back), speed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.RotateAround(pivot.transform.position, transform.TransformDirection(Vector3.back), -speed * Time.deltaTime);
        }
        
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
