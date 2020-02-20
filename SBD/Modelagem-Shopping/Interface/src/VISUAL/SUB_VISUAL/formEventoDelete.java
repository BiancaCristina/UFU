package VISUAL.SUB_VISUAL;

import TABELAS.Evento;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class formEventoDelete extends javax.swing.JFrame {
    String user;
    String password;
    
    public formEventoDelete(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        this.setLocationRelativeTo(null);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        removerEvento = new javax.swing.JButton();
        nomeEvento = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        mes = new javax.swing.JTextField();
        ano = new javax.swing.JTextField();
        dia = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Data do Evento:");

        removerEvento.setText("Remover");
        removerEvento.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removerEventoActionPerformed(evt);
            }
        });

        jLabel2.setText("Nome do Evento:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel2)
                    .addComponent(jLabel1))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(removerEvento, javax.swing.GroupLayout.DEFAULT_SIZE, 182, Short.MAX_VALUE)
                    .addComponent(nomeEvento)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(dia, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(mes, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(ano)))
                .addContainerGap(69, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel1)
                        .addComponent(dia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(mes, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(ano, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(nomeEvento, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(26, 26, 26)
                .addComponent(removerEvento)
                .addContainerGap(28, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void removerEventoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removerEventoActionPerformed
        try { 
            Evento evento = new Evento(this.user, this.password);
            
            String d = dia.getText();
            String m = mes.getText();
            String a = ano.getText();
            Integer day = Integer.parseInt(d);
            Integer month = Integer.parseInt(m);
            Integer year = Integer.parseInt(a);
            
            if (d.length() > 2 || m.length() > 2 || a.length() > 4) {
                JOptionPane.showMessageDialog(null, "Data mal formatada!");
                dispose();
            }
            
            else if (day < 1 || day > 31 || month < 1 || month > 12 || year > 2030) {
                JOptionPane.showMessageDialog(null, "Data mal formatada!");
                dispose();
            }
            
            else {
                String data = dia.getText() + "/" + mes.getText() + "/" + ano.getText();

                evento.Delete(data, nomeEvento.getText());
                dispose();
            }
             
        } 
        
        catch (ClassNotFoundException ex) {
            Logger.getLogger(formEventoDelete.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_removerEventoActionPerformed


    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formEventoDelete().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField ano;
    private javax.swing.JTextField dia;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField mes;
    private javax.swing.JTextField nomeEvento;
    private javax.swing.JButton removerEvento;
    // End of variables declaration//GEN-END:variables
}
