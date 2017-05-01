protocol Protocol
{
    message Message1;

    message Message2;

    message Message3
    {
        string Field;
    }

    message Message4
    {
        string Field;
    }

    processor Processor1();

    processor Processor2()
    {
    }

    processor Processor3()
    {
        recv Recv1;
        recv Recv2;
        @L recv Recv3;
        recv Recv4;
    }

    processor Processor4() : Processor3(Message1, Message2)
    {
        recv Recv1(Message1);
        recv Recv2(Message2);
        @L recv Recv3(Message1);
        recv Recv4(Message2);
    }

    processor Processor5(string) : Processor3(Message3.Field, Message4.Field)
    {
        recv Recv1(Message3);
        recv Recv2(Message4);
        @L recv Recv3(Message3);
        recv Recv4(Message4);
    }

    processor Processor6() =! Processor3;

    processor Processor7() : Processor6(Message1, Message2) =! Processor4;

    processor Processor8(string) : Processor6(Message3.Field, Message4.Field) =! Processor5;
}