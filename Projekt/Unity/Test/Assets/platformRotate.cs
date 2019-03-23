using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class platformRotate : MonoBehaviour
{
    float speed = 50f;
    //public Transform holder;
    //public Transform cube1;
    //float previousRotation = 0;
    public GameObject pivot;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //var holderRotation = holder.rotation.y;
        //Rigidbody cube = cube1.GetComponent<Rigidbody>();
        //transform.rotation = holder.rotation;
        if (Input.GetKey(KeyCode.UpArrow))
        {
            //transform.Rotate(Vector3.back, speed * Time.deltaTime);
            transform.RotateAround(pivot.transform.position, transform.TransformDirection(Vector3.back), speed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.RotateAround(pivot.transform.position, transform.TransformDirection(Vector3.back), -speed * Time.deltaTime);
            //transform.Rotate(Vector3.back, -speed * Time.deltaTime);
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
