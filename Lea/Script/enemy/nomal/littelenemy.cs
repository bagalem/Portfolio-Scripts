using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class littelenemy : Enemy
{
    //���� ������ �޷��ִ� �ڵ�
    Rigidbody2D rd;
    public override void Start()
    {
        base.Start();
        rd = GetComponent<Rigidbody2D>();
    }
    public override void Update()
    {
        base.Update();
    }

    private void FixedUpdate()
    {
        move();
    }

    public override void OnCollisionEnter2D(Collision2D collision)
    {
        base.OnCollisionEnter2D(collision);
    }
    //�÷��̾� ���󰡴� �ڵ�
    void move()
    {
        Vector2 moveDirection = (target.transform.position - transform.position).normalized;
        rd.velocity = new Vector2((moveDirection.x * 100) * moveSpeed * Time.deltaTime, (moveDirection.y * 100) * moveSpeed * Time.deltaTime);
    }

}

