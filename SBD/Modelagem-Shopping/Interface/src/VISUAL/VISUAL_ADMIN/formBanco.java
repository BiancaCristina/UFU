package VISUAL.VISUAL_ADMIN;

import VISUAL.formAdminUser;
import VISUAL.SUB_VISUAL.formBancoDelete;
import VISUAL.SUB_VISUAL.formBancoInsert;

public class formBanco extends javax.swing.JFrame {
    String user;
    String password;
    
    public formBanco(String user, String password) {
        this.user = user;
        this.password = password;
       
        initComponents();
        cogumelo1.setVisible(false);
        cogumelo2.setVisible(false);
        cogumeloMenu.setVisible(false);
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        cogumelo4 = new javax.swing.JLabel();
        bancoDelete = new javax.swing.JButton();
        bancoInsert = new javax.swing.JButton();
        bancoMenuAnterior = new javax.swing.JButton();
        cogumelo1 = new javax.swing.JLabel();
        cogumelo2 = new javax.swing.JLabel();
        cogumeloMenu = new javax.swing.JLabel();

        cogumelo4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        bancoDelete.setText("Remover Banco");
        bancoDelete.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                bancoDeleteMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                bancoDeleteMouseEntered(evt);
            }
        });
        bancoDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bancoDeleteActionPerformed(evt);
            }
        });

        bancoInsert.setText("Inserir Banco");
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

        cogumeloMenu.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(76, 76, 76)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(cogumelo1)
                    .addComponent(cogumelo2)
                    .addComponent(cogumeloMenu))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(bancoDelete, javax.swing.GroupLayout.DEFAULT_SIZE, 154, Short.MAX_VALUE)
                    .addComponent(bancoInsert, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(bancoMenuAnterior, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(65, Short.MAX_VALUE))
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
                    .addComponent(bancoDelete)
                    .addComponent(cogumelo2))
                .addGap(43, 43, 43)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(bancoMenuAnterior)
                    .addComponent(cogumeloMenu))
                .addContainerGap(33, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void bancoInsertActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bancoInsertActionPerformed

        formBancoInsert form = new formBancoInsert(this.user, this.password); 
        form.setVisible(true);
        
    }//GEN-LAST:event_bancoInsertActionPerformed

    private void bancoDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bancoDeleteActionPerformed
        
        formBancoDelete form = new formBancoDelete(this.user, this.password);
        form.setVisible(true);
    }//GEN-LAST:event_bancoDeleteActionPerformed

    private void bancoInsertMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoInsertMouseEntered
        // TODO add your handling code here:
        cogumelo1.setVisible(true);
    }//GEN-LAST:event_bancoInsertMouseEntered

    private void bancoInsertMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoInsertMouseExited
        // TODO add your handling code here:
        cogumelo1.setVisible(false);
    }//GEN-LAST:event_bancoInsertMouseExited

    private void bancoDeleteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoDeleteMouseEntered
        // TODO add your handling code here:
        cogumelo2.setVisible(true);
    }//GEN-LAST:event_bancoDeleteMouseEntered

    private void bancoDeleteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoDeleteMouseExited
        // TODO add your handling code here:
        cogumelo2.setVisible(false);
    }//GEN-LAST:event_bancoDeleteMouseExited

    private void bancoMenuAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorActionPerformed
        formAdminUser form = new formAdminUser(this.user, this.password);

        form.setVisible(true);
        dispose();
    }//GEN-LAST:event_bancoMenuAnteriorActionPerformed

    private void bancoMenuAnteriorMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorMouseEntered
        // TODO add your handling code here:
        cogumeloMenu.setVisible(true);
    }//GEN-LAST:event_bancoMenuAnteriorMouseEntered

    private void bancoMenuAnteriorMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_bancoMenuAnteriorMouseExited
        // TODO add your handling code here:
        cogumeloMenu.setVisible(false);
    }//GEN-LAST:event_bancoMenuAnteriorMouseExited

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formBanco().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bancoDelete;
    private javax.swing.JButton bancoInsert;
    private javax.swing.JButton bancoMenuAnterior;
    private javax.swing.JLabel cogumelo1;
    private javax.swing.JLabel cogumelo2;
    private javax.swing.JLabel cogumelo4;
    private javax.swing.JLabel cogumeloMenu;
    // End of variables declaration//GEN-END:variables
}
