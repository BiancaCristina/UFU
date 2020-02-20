package VISUAL.SUB_VISUAL;

import TABELAS.Funcionario;
import TABELAS.Organizador;
import java.util.logging.Level;
import java.util.logging.Logger;

public class formOrganizadorUpdate extends javax.swing.JFrame {
    String user;
    String password;
    
    public formOrganizadorUpdate(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        cpfOrganizador = new javax.swing.JTextField();
        nomeOrganizador = new javax.swing.JTextField();
        atualizarOrganizador = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("CPF:");

        jLabel2.setText("Nome:");

        cpfOrganizador.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cpfOrganizadorActionPerformed(evt);
            }
        });

        nomeOrganizador.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nomeOrganizadorActionPerformed(evt);
            }
        });

        atualizarOrganizador.setText("Atualizar");
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
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(13, 13, 13)
                        .addComponent(jLabel1)
                        .addGap(27, 27, 27))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addGap(18, 18, 18)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(atualizarOrganizador, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(nomeOrganizador, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(cpfOrganizador, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(44, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(cpfOrganizador, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel2)
                    .addComponent(nomeOrganizador, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(26, 26, 26)
                .addComponent(atualizarOrganizador)
                .addContainerGap(20, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cpfOrganizadorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cpfOrganizadorActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cpfOrganizadorActionPerformed

    private void nomeOrganizadorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nomeOrganizadorActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_nomeOrganizadorActionPerformed

    private void atualizarOrganizadorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_atualizarOrganizadorActionPerformed
        // TODO add your handling code here:
    try {
            Organizador organizador = new Organizador(this.user, this.password);

            organizador.Update(cpfOrganizador.getText(), nomeOrganizador.getText());

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
    private javax.swing.JTextField cpfOrganizador;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField nomeOrganizador;
    // End of variables declaration//GEN-END:variables
}
