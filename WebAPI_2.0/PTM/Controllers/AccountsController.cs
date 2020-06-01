
using System;
using System.Collections.Generic;
using Microsoft.AspNetCore.Mvc;
using System.Linq;
using System.Threading.Tasks;
using PTM.Models;
using PTM.Data;

namespace PTM.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AccountsController : ControllerBase
    {
        /// <summary>
        /// Tylko do testowania, wszystkie konta
        /// </summary>
        [HttpGet]
        public IEnumerable<AccountModel> Get()
        {
            return Database.Accounts;
        }

        /// <summary>
        /// Tylko do testowania
        /// </summary>
        [HttpGet("{id}")]
        public ActionResult<AccountModel> Get(string id)
        {
            AccountModel account = Database.Accounts.FirstOrDefault(x => x.Id == id);
            if (account == null)
            {
                Database.Accounts.Add(new AccountModel() { Id = id });
                Database.SaveChanges();
                return Database.Accounts.FirstOrDefault(x => x.Id == id);
            }
            return account;
        }

        // GET: api/Accounts/5
        [HttpGet("{id}/balance")]
        public ActionResult<double> GetBalance(string id)
        {
            AccountModel account = Database.Accounts.FirstOrDefault(x => x.Id == id);
            if (account == null)
            {
                Database.Accounts.Add(new AccountModel(){Id = id});
                Database.SaveChanges();
                return Database.Accounts.FirstOrDefault(x => x.Id == id).Balance;
            }

            return account.Balance;
        }

        /// <summary>
        /// Ustawianie salda
        /// </summary>
        [HttpGet("{id}/balance/{value}")]
        public ActionResult<AccountModel> Put(string id, double value)
        {
            AccountModel account = Database.Accounts.FirstOrDefault(x => x.Id == id);
            if (account == null)
                return NotFound();
            account.Balance = value;
            Database.SaveChanges();
            return account;
        }

        // GET: api/Accounts/5/pin
        [HttpGet("{id}/pin")]
        public ActionResult<double> GetPin(string id)
        {
            AccountModel account = Database.Accounts.FirstOrDefault(x => x.Id == id);
            if (account == null)
            {
                Database.Accounts.Add(new AccountModel() { Id = id });
                Database.SaveChanges();
                return Database.Accounts.FirstOrDefault(x => x.Id == id).Balance;
            }

            return account.Pin;
        }

        /// <summary>
        /// Tylko do testowania, dodawanie nowego konta
        /// </summary>
        [HttpPost]
        public ActionResult<AccountModel> Post([FromBody] AccountModel account)
        {
            Database.Accounts.Add(account);
            Database.SaveChanges();
            return account;
        }


        /*
        /// <summary>
        /// Przelew między kontami
        /// </summary>
        // GET: api/Accounts/51/transferTo/515/1515
        [HttpGet("{from}/transferTo/{to}/{value}")]
        public ActionResult<AccountModel> Transfer(string from, string to, double value)
        {
            AccountModel accountFrom = Database.Accounts.FirstOrDefault(x => x.Id == from);
            AccountModel accountTo = Database.Accounts.FirstOrDefault(x => x.Id == to);
            if (accountFrom == null || accountTo == null)
                return NotFound();
            //if (value < accountFrom.Balance)      // STM will check that
            //    return Conflict();

            accountFrom.Balance -= value;
            accountTo.Balance += value;
            Database.SaveChanges();
            return Ok();
        }*/



        // Method not necessary
        /* DELETE: api/Accounts/5
        [HttpDelete("{id}/delet")]
        public ActionResult Delete(string id)
        {
            AccountModel account = Database.Accounts.FirstOrDefault(x => x.Id == id);
            if (account == null)
                return NotFound();
            Database.Accounts.Remove(account);
            Database.SaveChanges();
            return Ok();
        } */
    }
}