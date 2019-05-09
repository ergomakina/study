type bank_account = { name: string; mutable amount: int}

let alice = {name="Alice";amount=10000};;

alice.amount <- alice.amount + 2000;;