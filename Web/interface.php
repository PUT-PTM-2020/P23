<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css" integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js" integrity="sha384-OgVRvuATP1z7JjHLkuOU7Xw704+h835Lr+6QL9UvYjZE3Ipu6Tp75j7Bh/kR0JKI" crossorigin="anonymous"></script>

    <link href="https://fonts.googleapis.com/css2?family=Comfortaa:wght@300;700&display=swap" rel="stylesheet">

    <link rel="stylesheet" type="text/css" href="fontello/css/fontello.css">

    <title>Witaj w naszym banku!</title>

    <style>
        body{
            font-family: 'Comfortaa', cursive;
        }
        a{
            width: inherit;
            height: inherit;
            text-decoration: none;
            font-size: 32px;
            text-align: center;
            padding: 10px
        }
        a:hover{
            text-decoration: none;
        }
        .saldo:hover{
            background-color: #ec407a;
            border-radius: 15px;
        }
        .przelew:hover{
            background-color: #66bb6a;
            border-radius: 15px;
        }
        .wplata:hover{
            background-color: #7e57c2;
            border-radius: 15px;
        }
        .wyplata:hover{
            background-color: #ffb74d;
            border-radius: 15px;
        }
        .akcjaItem{
            border-radius: 15px;
        }
    </style>
</head>
<body>
  
<!-- Button trigger modal -->

<div class="container d-flex justify-content-center align-items-center" style="height: 100vh;">
    <button style="background: url('karta.jpg') no-repeat; width: 542px; height: 344px;" class="btn" href="#pinModal" data-toggle="modal" style="color: black;" data-dismiss="modal"></button>
</div>

<!-- pinmodal -->
<div class="modal fade" id="pinModal">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title">Podaj kod Pin</h3>
                <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
            </div>
            <form>
                <div class="modal-body d-flex justify-content-center">
                    <input type="password" name="pin" style="width: 6rem; font-size: 32px; text-align: center;" />
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">Wróć</button>
                    <a class="btn btn-primary" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Dalej</a>
                </div>
            </form>
        </div>
    </div>
</div>
  
<!-- operacje modal -->
<div class="modal fade" data-backdrop="static" id="operacjaModal">
    <div class="modal-dialog modal-lg">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title" id="exampleModalLabel">Witaj Julia!</h3>
            </div>
            <div class="modal-body">
                <div class="row d-flex justify-content-center">
                        <div class="col-md-5 d-flex justify-content-center align-items-center akcjaItem" style="height: 10rem; background-color: #c2185b; margin: 10px; padding: 0px;"><a href="#saldoModal" data-toggle="modal" style="color: white;" data-dismiss="modal" class="saldo">Sprawdź saldo<br><i class="icon-wallet" style="font-size: 48px;"></i></a></div>
                        <div class="col-md-5 d-flex justify-content-center align-items-center akcjaItem" style="height: 10rem; background-color: #43a047; color: black; margin: 10px; padding: 0px;"><a href="#przelejModal" style="color: white;" data-toggle="modal" data-dismiss="modal" class="przelew">Przelej pieniądze<br><i class="icon-switch" style="font-size: 48px;"></i></a></div>
                    </div>
                    <div class="row d-flex justify-content-center">
                        <div class="col-md-5 d-flex justify-content-center align-items-center akcjaItem" style="height: 10rem; background-color: #512da8; margin: 10px; padding: 0px;"><a href="#wplataModal" style="color: white;" data-toggle="modal" data-dismiss="modal" class="wplata">Wpłać pieniądze<br><i class="icon-login" style="font-size: 48px;"></i></a></div>
                        <div class="col-md-5 d-flex justify-content-center align-items-center akcjaItem" style="height: 10rem; background-color: #fb8c00; margin: 10px; padding: 0px;"><a href="#wyplataModal" style="color: white;" data-toggle="modal" data-dismiss="modal" class="wyplata">Wypłać pieniądze<br><i class="icon-logout" style="font-size: 48px;"></i></a></div>
                    </div>
                </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-primary" data-dismiss="modal">Zakończ</button>
            </div>
        </div>
    </div>
</div>

<!-- saldo modal -->
<div class="modal fade" data-backdrop="static" id="saldoModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title" id="exampleModalLabel">Twoje saldo</h3>
            </div>
            <div class="modal-body">
                14,28 zł
            </div>
            <div class="modal-footer">
                <a class="btn btn-warning" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Wróć</a>
            </div>
        </div>
    </div>
</div>

<!-- przelej modal -->
<div class="modal fade" data-backdrop="static" id="przelejModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title" id="exampleModalLabel">Dokonaj przelewu</h3>
            </div>
            <form>
                <div class="modal-body">
                    <div class="form-group">
                        <label for="exampleInputEmail1">ID Odbiorcy</label>
                        <input type="text" class="form-control">
                    </div>
                    <div class="form-group">
                        <label for="exampleInputPassword1">Kwota</label>
                        <input type="text" class="form-control">
                    </div>
                    <div class="form-group">
                        <label for="exampleInputPassword1">Zatwierdź kodem Pin</label>
                        <input type="password" class="form-control">
                    </div>
                </div>
                <div class="modal-footer">
                    <a class="btn btn-warning" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Wróć</a>
                    <a class="btn btn-primary" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Zatwierdź</a>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- wplac modal -->
<div class="modal fade" data-backdrop="static" id="wplataModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title" id="exampleModalLabel">Zasil swoje konto</h3>
            </div>
            <form>
                <div class="modal-body">
                    <div class="form-group">
                        <label for="exampleInputEmail1">Kwota</label>
                        <input type="text" class="form-control">
                    </div>
                </div>
                <div class="modal-footer">
                    <a class="btn btn-warning" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Wróć</a>
                    <a class="btn btn-primary" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Zatwierdź</a>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- wyplac modal -->
<div class="modal fade" data-backdrop="static" id="wyplataModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h3 class="modal-title" id="exampleModalLabel">Wypłać swoje pieniądze</h3>
            </div>
            <form>
                <div class="modal-body" style="font-size: 22px;">
                    <div class="form-row">
                        <div class="col">
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="inlineRadioOptions" id="opcja1" value="opcja1">
                                <label class="form-check-label" for="opcja1">20</label>
                            </div>
                        </div>
                        <div class="col">
                            <div class="form-check form-check-inline float-right">
                                <label class="form-check-label" for="opcja2" style="padding-right: 6px;">50</label>
                                <input class="form-check-input" type="radio" name="inlineRadioOptions" id="opcja2" value="opcja2">
                            </div>
                        </div>
                    </div>
                    <div class="form-row">
                        <div class="col">
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="inlineRadioOptions" id="opcja3" value="opcja3">
                                <label class="form-check-label" for="opcja3">100</label>
                            </div>
                        </div>
                        <div class="col">
                            <div class="form-check form-check-inline float-right">
                                <label class="form-check-label" for="opcja4" style="padding-right: 6px;">200</label>
                                <input class="form-check-input" type="radio" name="inlineRadioOptions" id="opcja4" value="opcja4">
                            </div>
                        </div>
                    </div>
                    <div class="form-row">
                        <div class="col">
                            <div class="form-check form-check-inline">
                                <label class="form-check-label" for="opcja5">Niestandardowe: </label>
                                <input class="form-check-input" type="text" name="inlineRadioOptions" id="opcja5" value="">
                            </div>
                        </div>
                    </div>
                </div>
                <div class="modal-footer">
                    <a class="btn btn-warning" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Wróć</a>
                    <a class="btn btn-primary" href="#operacjaModal" data-toggle="modal" data-dismiss="modal">Zatwierdź</a>
                </div>
            </form>
        </div>
    </div>
</div>


<!-- #modal template -->
<div class="modal fade" id="modal-3">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <h4 class="modal-title">Modal title</h4>
      </div>
      <div class="modal-body">
        <p>Modal 3</p>
        
  <a href="#modal-2" data-toggle="modal" data-dismiss="modal">< Previous</a>
        
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
        <button type="button" class="btn btn-primary">Save changes</button>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->  
  