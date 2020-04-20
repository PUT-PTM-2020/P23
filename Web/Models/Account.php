<?php 

class Account{
    /** @var float */
    public $balance;

    /** @var string */
    public $id;

    public function __construct(string $id, float $balance)
    {
        $this->balance = $balance;
        $this->id = $id;
    }

    public function GetBalance(): float
    {
        return $this->balance;
    }

    public function SetBalance(float $balance): void
    {
        $this->balance = $balance;
    }

    public function GetId(): string
    {
        return $this->id;
    }
}
