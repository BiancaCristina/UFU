namespace java chavevalor
namespace py chavevalor


exception KeyNotFound
{
}


service ChaveValor
{
    string getKV(1:i32 key) throws (1:KeyNotFound knf),
    bool setKV(1:i32 key, 2:string value),
    void delKV(1:i32 key)
}

package chavevalor;

import java.util.HashMap;

public class NewChaveValorHandler {
    private HashMap<Integer,String> kv = new HashMap<>();
    @Override
    public String getKV(int key) throws TException {
        // Same as before
        if(kv.containsKey(key))
            return kv.get(key);
        else
            throw new KeyNotFound();
    }
    @Override
    public String setKV(int key, String valor) throws TException {
        // Return empty if value doesn't exists
        String oldValue = "";
        if (kv.containsKey(key)) {
            oldValue = kv.get(key);
        }
        kv.put(key,valor);
        return oldValue;

    }
    @Override
    public void delKV(int key) throws TException {
        // Same as before
        kv.remove(key);
    }
}