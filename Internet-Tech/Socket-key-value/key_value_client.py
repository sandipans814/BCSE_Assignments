from threading import Lock

global_dict: dict = {}

lock: Lock = Lock()

class KeyValueClient:
    manager_password: str = "managerpassword123"

    def __init__(self, username: str) -> None:
        self.username: str = username
        self.role: str = "guest"
        self.store: dict[str, str] = {}

    def get(self, key: str) -> str:
        try:
            return self.store[key]
        except:
            return "<blank>"

    def put(self, key: str, value: str) -> str:
        try:
            lock.acquire()
            print("Lock acquired")
            self.store[key] = value
            lock.release()
            print("Lock released")
            return "Put was successful."
        except:
            return "Put failed."

    def upgrade(self, password: str) -> str:
        if password == KeyValueClient.manager_password:
            self.role = "manager"
            return "Upgrade was successful."
        else:
            return "Invalid password. Upgrade failed."

    def getother(self, username: str, key: str) -> str:
        try:
            if self.role == "manager":
                return global_dict[username].get(key)
            else:
                return "You do not have managerial access."
        except:
            return "<blank>"

    def putother(self, username: str, key: str, value: str) -> str:
        try:
            if self.role == "manager":
                global_dict[username].put(key, value)
                return "Putother was successful."
            else:
                return "You do not have managerial access."
        except:
            return "Invalid username. Putother failed."

    def resolve_util(self, request: dict[str, str]) -> str:
        if( request["method"].lower() == "get" ):
            return self.get(request["key"])
        elif ( request["method"].lower() == "put" ):
            return self.put(request["key"], request["value"])
        elif ( request["method"].lower() == "upgrade" ):
            return self.upgrade(request["password"])
        elif ( request["method"].lower() == "getother" ):
            return self.getother(request["username"], request["key"])
        elif ( request["method"].lower() == "putother" ):
            return self.putother(request["username"], request["key"], request["value"])
        return 'Invalid command'

    def resolve(self, request: list[dict[str, str]]) -> list[str]:
        response: list[str] = list(map(self.resolve_util, request))

        return response

    def __str__(self):
        return str(self.store)