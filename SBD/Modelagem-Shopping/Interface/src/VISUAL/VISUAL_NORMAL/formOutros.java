package VISUAL.VISUAL_NORMAL;

import VISUAL.SUB_VISUAL.formFuncionarioInsert;
import VISUAL.SUB_VISUAL.formOrganizadorUpdate;
import VISUAL.SUB_VISUAL.formTipoComodoDelete;
import VISUAL.formNormalUser;

public class formOutros extends javax.swing.JFrame {
    String user;
    String password;
    
    public formOutros(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        
        cogumelo1.setVisible(false);
        cogumelo2.setVisible(false);
        cogumelo3.setVisible(false);
        cogumelo4.setVisible(false);        
        
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        tipoComodoDelete = new javax.swing.JButton();
        bancoInsert = new javax.swing.JButton();
        organizadorAtualiza = new javax.swing.JButton();
        bancoMenuAnterior = new javax.swing.JButton();
        cogumelo1 = new javax.swing.JLabel();
        cogumelo2 = new javax.swing.JLabel();
        cogumelo3 = new javax.swing.JLabel();
        cogumelo4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        tipoComodoDelete.setText("Remover Tipo de Cômodo");
        tipoComodoDelete.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                tipoComodoDeleteMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                tipoComodoDeleteMouseEntered(evt);
            }
        });
        tipoComodoDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tipoComodoDeleteActionPerformed(evt);
            }
        });

        bancoInsert.setText("Inserir Funcionário");
        bancoInsert.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                bancoInsertMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                bancoInsertMouseEntered(evt);
            }
        });
        bancoInsert.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bancoInsertActionPerformed(evt);
            }
        });

        organizadorAtualiza.setText("Atualiza Organizador");
        organizadorAtualiza.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                organizadorAtualizaMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                organizadorAtualizaMouseEntered(evt);
            }
        });
        organizadorAtualiza.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                organizadorAtualizaActionPerformed(evt);
            }
        });

        bancoMenuAnterior.setText("Menu Anterior");
        bancoMenuAnterior.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                bancoMenuAnteriorMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                bancoMenuAnteriorMouseEntered(evt);
            }
        });
        bancoMenuAnterior.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bancoMenuAnteriorActionPerformed(evt);
            }
        });

        cogumelo1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(76, 76, 76)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(cogumelo1)
                    .addComponent(cogumelo2)
                    .addComponent(cogumelo3)
                    .addComponent(cogumelo4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(organizadorAtualiza, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(tipoComodoDelete, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(bancoInsert, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(bancoMenuAnterior, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(111, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(bancoInsert)
                    .addComponent(cogumelo1))
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(tipoComodoDelete)
                    .addComponent(cogumelo2))
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(organizadorAtualiza)
                    .addComponent(cogumelo3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 42, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(bancoMenuAnterior)
                    .addComponent(cogumelo4))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void bancoInsertActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bancoInsertActionPerformed
   
        formFuncionarioInsert form = new formFuncionarioInsert(this.user, this.password);
        form.setVisible(true);
              
    }//GEN-LAST:event_bancoInsertActionPerformed

    private void tipoComodoDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tipoComodoDeleteActionPerformed
        formTipoComodoDelete form = new formTipoComodoDelete(this.user, this.password);
        form.setVisible(true);
        
    }//GEN-LAST:event_tipoComodoDeleteActionPerformed

    private void organizadorAtualizaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_organizadorAtualizaActionPerformed
        formOrganizadorUpdate form = new formOrganizadorUpdate(this.user, this.password);
        form.setVisible(true);
    }//GEN-LAST:event_organizadorAtualizaActionPerformed

    private void bancoMenuAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorActionPerformed
        formNormalUser form = new formNormalUser(this.user, this.password);
        
        form.setVisible(true);
        dispose();
    }//GEN-LAST:event_bancoMenuAnteriorActionPerformed

    private void bancoInsertMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoInsertMouseEntered
        // TODO add your handling code here:
        cogumelo1.setVisible(true);
    }//GEN-LAST:event_bancoInsertMouseEntered

    private void bancoInsertMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoInsertMouseExited
        // TODO add your handling code here:
        cogumelo1.setVisible(false);
    }//GEN-LAST:event_bancoInsertMouseExited

    private void tipoComodoDeleteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tipoComodoDeleteMouseEntered
        // TODO add your handling code here:
        cogumelo2.setVisible(true);
    }//GEN-LAST:event_tipoComodoDeleteMouseEntered

    private void tipoComodoDeleteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tipoComodoDeleteMouseExited
        // TODO add your handling code here:
        cogumelo2.setVisible(false);
    }//GEN-LAST:event_tipoComodoDeleteMouseExited

    private void organizadorAtualizaMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_organizadorAtualizaMouseEntered
        // TODO add your handling code here:
        cogumelo3.setVisible(true);
    }//GEN-LAST:event_organizadorAtualizaMouseEntered

    private void organizadorAtualizaMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_organizadorAtualizaMouseExited
        // TODO add your handling code here:
        cogumelo3.setVisible(false);
    }//GEN-LAST:event_organizadorAtualizaMouseExited

    private void bancoMenuAnteriorMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorMouseEntered
        // TODO add your handling code here:
        cogumelo4.setVisible(true);
    }//GEN-LAST:event_bancoMenuAnteriorMouseEntered

    private void bancoMenuAnteriorMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorMouseExited
        // TODO add your handling code here:
        cogumelo4.setVisible(false);
    }//GEN-LAST:event_bancoMenuAnteriorMouseExited

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formOutros().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bancoInsert;
    private javax.swing.JButton bancoMenuAnterior;
    private javax.swing.JLabel cogumelo1;
    private javax.swing.JLabel cogumelo2;
    private javax.swing.JLabel cogumelo3;
    private javax.swing.JLabel cogumelo4;
    private javax.swing.JButton organizadorAtualiza;
    private javax.swing.JButton tipoComodoDelete;
    // End of variables declaration//GEN-END:variables
}
