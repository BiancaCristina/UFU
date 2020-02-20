package VISUAL.SUB_VISUAL;

import TABELAS.Funcionario;
import TABELAS.Organizador;
import TABELAS.TipoComodo;
import java.util.logging.Level;
import java.util.logging.Logger;

public class formTipoComodoDelete extends javax.swing.JFrame {
    String user;
    String password;
    
    public formTipoComodoDelete(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        numeroTipoComodo = new javax.swing.JTextField();
        atualizarOrganizador = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Identificador:");

        numeroTipoComodo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                numeroTipoComodoActionPerformed(evt);
            }
        });

        atualizarOrganizador.setText("Remover");
        atualizarOrganizador.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                atualizarOrganizadorActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(jLabel1)
                .addGap(31, 31, 31)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(atualizarOrganizador, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(numeroTipoComodo, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(numeroTipoComodo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addGap(18, 18, 18)
                .addComponent(atualizarOrganizador)
                .addContainerGap(53, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void numeroTipoComodoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_numeroTipoComodoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_numeroTipoComodoActionPerformed

    private void atualizarOrganizadorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_atualizarOrganizadorActionPerformed
        // TODO add your handling code here:
    try {
            TipoComodo tipoComodo = new TipoComodo(this.user, this.password);
            
            Integer numero_identificador = Integer.parseInt(numeroTipoComodo.getText());
            
            tipoComodo.Delete(numero_identificador);
            
            dispose();
        } 
        
    catch (ClassNotFoundException ex) {
            Logger.getLogger(formBancoInsert.class.getName()).log(Level.SEVERE, null, ex);
        }  
    }//GEN-LAST:event_atualizarOrganizadorActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formFuncionarioInsert().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton atualizarOrganizador;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField numeroTipoComodo;
    // End of variables declaration//GEN-END:variables
}
