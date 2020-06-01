using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PTM.Models
{
    public class AccountModel
    {
        public string Id { get; set; }
        public string OwnerName { get; set; }
        public int Pin { get; set; } = 1234;
        public double Balance { get; set; }
    }
}
