﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _231101C__Exam1
{
    public class DomesticCat : Cat
    {
        public string masterName {  get; set; }

        public override void eat()
        {
            Console.WriteLine(masterName+"이먹여줘요");
        }

        public override void grooming()
        {
            Console.WriteLine(masterName+"이 빗겨줘요");
        }

        public override void hunt()
        {
            Console.WriteLine(masterName + "이 주는것만 먹어요");
        }

        public override void sleep()
        {
            Console.WriteLine(masterName + "가 재워줍니다");
        }
    }
}
