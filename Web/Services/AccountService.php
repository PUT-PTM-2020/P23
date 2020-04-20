<?php 
include_once 'Models/Account.php';

class AccountService
{
    private $dbFile = "db.txt";
    private $accounts = null;

    public function GetAccount(string $accountId)
    {
        foreach($this->GetAllAccounts() as $account)
        {
            if($account->id == $accountId)
                return $account;
        }
        return null;
    }

    /**
     * Undocumented function
     *
     * @return Account[]
     */
    public function GetAllAccounts()
    {
        if($this->accounts != null)
            return $this->accounts;
        if(!file_exists($this->dbFile))
            return $this->accounts = array();
        $fileContent = file_get_contents($this->dbFile);
        $accountsRaw = json_decode($fileContent);
        foreach($accountsRaw as $account)
        {
            $this->accounts[] = new Account($account->id, $account->balance);
        }
        return $this->accounts;
    }


    public function SaveChangesToServer()
    {
        file_put_contents( $this->dbFile, json_encode($this->GetAllAccounts() , JSON_PRETTY_PRINT) );
    }

    public function CreateNewAccount( string $accountId = null ): Account
    {
        if( $accountId == null ) $accountId = uniqid();
        $account = new Account($accountId, 0);
        $this->GetAllAccounts();
        $this->accounts[] = $account;
        var_dump($this->accounts);
        $this->SaveChangesToServer();
        return $account;
    }
}