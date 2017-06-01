protocol Protocol
{
    enum Enum
    {
        Value1,
        Value2
    }

    set Set
    {
        Value1,
        Value2
    }

    const int32 Const1 = -10;

    message Message
    {
        bool Field1;
        Enum Field2;
        Set Field3;        
        int32 Field4;
        uint32 Field5;
        string Field6;
        double Field7;
    }

    processor Processor()
    {
        recv Recv1(Message : Field1);

        recv Recv2(Message : Field2 == Enum.Value1);

        recv Recv3(Message : Field3 == Set.Value1);

        recv Recv4(Message : Field4 == Const1);

        recv Recv5(Message : Field5 == 10);

        recv Recv6(Message : Field6 == "abc");

        recv Recv7(Message : Field7 == 3.14159);

        recv Recv8(Message : ! Field1);

        recv Recv9(Message : Field2 != Enum.Value1);

        recv Recv10(Message : Field3 != Set.Value1);

        recv Recv11(Message : Field4 != Const1);

        recv Recv12(Message : Field5 != 10);

        recv Recv13(Message : Field6 != "abc");

        recv Recv14(Message : Field7 !=  3.14159);

        recv Recv15(Message : Field1 && Field2 == Enum.Value1);

        recv Recv16(Message : ! Field1 || Field2 != Enum.Value1);

        recv Recv17(Message : ! ((Field4 == -10 || Field5 != 20) && (Field6 == "abc" || Field7 != 3.14159)));
    }
}
