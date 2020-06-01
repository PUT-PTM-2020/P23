using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;
using PTM.Models;

namespace PTM.Data
{
    public static class Database
    {
        public static List<AccountModel> Accounts { get; set; }
        private static string DatabaseAccountsFile = "DatabaseAccounts.txt";

        static Database()
        {
            if (File.Exists(DatabaseAccountsFile))
            {
                var fileContent = File.ReadAllText(DatabaseAccountsFile);
                Accounts = JsonSerializer.Deserialize<List<AccountModel>>(fileContent);
            }
            else
            {
                Accounts = new List<AccountModel>();
            }
        }

        public static void SaveChanges()
        {
            var accountsSerialized = JsonSerializer.Serialize(Accounts);
            File.WriteAllText(DatabaseAccountsFile, accountsSerialized);
        }
    } 
}
